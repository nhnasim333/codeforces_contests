#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> total(n + 1, 0);
        for (int x : a)
            total[x]++;

        bool ok = true;
        vector<int> limit(n + 1, 0);
        for (int v = 1; v <= n; v++)
        {
            if (total[v] % k != 0)
            {
                ok = false;
                break;
            }
            limit[v] = total[v] / k;
        }

        if (!ok)
        {
            cout << 0 << endl;
            continue;
        }

        long long ans = 0;
        vector<int> freq(n + 1, 0);
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            freq[a[r]]++;
            while (freq[a[r]] > limit[a[r]])
            {
                freq[a[l]]--;
                l++;
            }
            ans += (r - l + 1);
        }

        cout << ans << endl;
    }
    return 0;
}
