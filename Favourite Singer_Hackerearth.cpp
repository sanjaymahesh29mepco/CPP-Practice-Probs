#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    unordered_map<long long, long long> counts;
    long long max_freq = 0;


    for (int i = 0; i < n; ++i) {
        long long singer_id;
        cin >> singer_id;
        counts[singer_id]++;
        
        if (counts[singer_id] > max_freq) {
            max_freq = counts[singer_id];
        }
    }

   
    long long favourite_singers = 0;
    for (auto const& [id, freq] : counts) {
        if (freq == max_freq) {
            favourite_singers++;
        }
    }

    cout << favourite_singers << endl;

    return 0;
}
