#include <bits/stdc++.h>
using namespace std;

long long gcdLL(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcmLL(long long a, long long b) {
    return a / gcdLL(a, b) * b;
}

int main() {

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;

        vector<long long> p(n), s(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> s[i];

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = lcmLL(p[i], s[i]);
        }

        vector<long long> prefixGCD(n);
        prefixGCD[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefixGCD[i] = gcdLL(prefixGCD[i - 1], a[i]);
        }

        vector<long long> suffixGCD(n);
        suffixGCD[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixGCD[i] = gcdLL(suffixGCD[i + 1], a[i]);
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (prefixGCD[i] != p[i] || suffixGCD[i] != s[i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
