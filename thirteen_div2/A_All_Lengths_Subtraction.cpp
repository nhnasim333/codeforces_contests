#include <bits/stdc++.h>
using namespace std;

bool check_possible(int n, vector<int> &p)
{
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i)
    {
        pos[p[i]] = i;
    }

    vector<bool> removed(n, false);
    for (int x = 1; x <= n; ++x)
    {
        int idx = pos[x];
        removed[idx] = true;

        int l = idx, r = idx;
        while (l > 0 && !removed[l - 1])
            l--;
        while (r < n - 1 && !removed[r + 1])
            r++;

        if (r - l + 1 != n - x + 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        cout << (check_possible(n, p) ? "YES" : "NO") << endl;
    }
    return 0;
}