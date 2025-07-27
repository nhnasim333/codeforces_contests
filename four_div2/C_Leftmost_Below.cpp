#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        bool possible = true;
        long long min_so_far = b[0];
        for (int i = 1; i < n; ++i) {
            min_so_far = min(min_so_far, b[i-1]);
            if (b[i] < min_so_far) {
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}