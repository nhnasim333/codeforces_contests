#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);
        vector<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        if (n == 2)
        {
            cout << 0 << endl;
            continue;
        }

        vector<int> isLeaf(n + 1, 0);
        int totalLeaves = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (deg[i] == 1)
            {
                isLeaf[i] = 1;
                ++totalLeaves;
            }
        }

        vector<int> adjLeaves(n + 1, 0);
        for (int v = 1; v <= n; v++)
        {
            for (int to : g[v])
            {
                if (isLeaf[to])
                    adjLeaves[v]++;
            }
        }

        int ans = INT_MAX;
        for (int v = 1; v <= n; v++)
        {
            int ops = totalLeaves - adjLeaves[v] - isLeaf[v];
            ans = min(ans, ops);
        }
        cout << ans << endl;
    }
    return 0;
}
