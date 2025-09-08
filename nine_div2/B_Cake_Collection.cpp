#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end(), greater<long long>());

        long long k = min<long long>(n, m);
        long long ans = 0;
        for (long long i = 0; i < k; i++)
            ans += a[i] * (m - i);

        cout << ans << endl;
    }
    return 0;
}