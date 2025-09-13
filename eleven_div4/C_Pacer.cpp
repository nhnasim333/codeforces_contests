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

        vector<pair<long long, int>> req(n + 1);
        req[0] = {0, 0};

        for (int i = 1; i <= n; i++)
        {
            long long a;
            int b;
            cin >> a >> b;
            req[i] = {a, b};
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            long long len = req[i].first - req[i - 1].first;
            int start = req[i - 1].second, end = req[i].second;

            long long best = len;
            if ((best % 2) != ((end - start) & 1))
                best--;
            ans += best;
        }

        {
            long long len = m - req[n].first;
            ans += len;
        }

        cout << ans << endl;
    }

    return 0;
}