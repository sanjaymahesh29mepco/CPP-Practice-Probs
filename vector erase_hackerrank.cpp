#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x, a, b;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> x;
    v.erase(v.begin() + (x - 1));
    cin >> a >> b;
    v.erase(v.begin() + (a - 1), v.begin() + (b - 1));
    
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    return 0;
}
