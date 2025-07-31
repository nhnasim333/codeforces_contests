#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    DSU(int n) : parent(n + 1)
    {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y)
    {
        int a = find(x), b = find(y);
        if (a == b)
            return false;
        parent[b] = a;
        return true;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> seg(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> seg[i].first >> seg[i].second;
        }
        DSU dsu(2 * n + 2);
        vector<int> used;
        for (int i = 0; i < n; ++i)
        {
            int a = seg[i].first, b = seg[i].second;
            if (dsu.unite(a, b))
            {
                used.push_back(i);
            }
        }
        vector<pair<int, int>> chosen;
        for (int idx : used)
            chosen.push_back(seg[idx]);
        sort(chosen.begin(), chosen.end());
        int last = -1, total = 0;
        for (auto [a, b] : chosen)
        {
            if (a > last)
            {
                total += b - a;
                last = b;
            }
            else if (b > last)
            {
                total += b - last;
                last = b;
            }
        }
        cout << used.size() << endl;
        for (int i = 0; i < (int)used.size(); ++i)
        {
            cout << used[i] + 1 << (i + 1 == (int)used.size() ? '\n' : ' ');
        }
    }
    return 0;
}