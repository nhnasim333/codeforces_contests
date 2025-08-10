#include <bits/stdc++.h>
using namespace std;

long long min_rem(long long x, long long k)
{
    long long r = x % k;
    return min(r, (k - r) % k);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> s(n), t(n);
        for (auto &x : s)
            cin >> x;
        for (auto &x : t)
            cin >> x;

        for (int i = 0; i < n; i++)
            s[i] = min_rem(s[i], k);
        for (int i = 0; i < n; i++)
            t[i] = min_rem(t[i], k);

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
