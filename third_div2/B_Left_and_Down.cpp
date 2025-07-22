#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a, b, k;
        cin >> a >> b >> k;
        if (a <= k && b <= k) {
            cout << 1 << endl;
        } else if (a % k == 0 && b % k == 0) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}