#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    map<string, string> attributes;
    vector<string> tag_stack;
    string current_path = "";

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        if (line.substr(0, 2) == "</") {
            
            tag_stack.pop_back();
            current_path = "";
            for (const string& t : tag_stack) {
                current_path += (current_path.empty() ? "" : ".") + t;
            }
        } else {
            
            line = line.substr(1, line.length() - 2);
            stringstream ss(line);
            string tag_name, attr, eq, val;
            
            ss >> tag_name;
            tag_stack.push_back(tag_name);
            current_path = "";
            for (int j = 0; j < tag_stack.size(); ++j) {
                current_path += (j == 0 ? "" : ".") + tag_stack[j];
            }

            
            while (ss >> attr >> eq >> val) {
                
                if (val.back() == '>') val.pop_back(); 
                val = val.substr(1, val.length() - 2);
                attributes[current_path + "~" + attr] = val;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        string query;
        getline(cin, query);
        if (attributes.find(query) != attributes.end()) {
            cout << attributes[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
