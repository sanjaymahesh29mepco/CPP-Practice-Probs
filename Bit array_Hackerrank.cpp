#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N, S, P, Q;
    if (!(cin >> N >> S >> P >> Q)) return 0;

    const long long MOD = 1LL << 31;
    
    vector<bool> seen(MOD, false);

    long long current = S % MOD;
    seen[current] = true;
    int count = 1;

    for (int i = 1; i < N; ++i) {
        current = (current * P + Q) % MOD;
        if (seen[current]) {
            break;
        }
        seen[current] = true;
        count++;
    }

    cout << count << endl;
    return 0;
}
