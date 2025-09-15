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
        vector<int> p(n + 1);
        vector<int> present(n + 1, 0);
        vector<int> zeros;
        for (int i = 1; i <= n; ++i)
        {
            cin >> p[i];
            if (p[i] == 0)
                zeros.push_back(i);
            else
                present[p[i]] = 1;
        }

        vector<int> missing;
        for (int v = 1; v <= n; v++)
            if (!present[v])
                missing.push_back(v);

        auto compute_lr = [&](bool skip_forced, int forced_pos) -> pair<int, int>
        {
            int l = -1, r = -1;
            for (int i = 1; i <= n; i++)
            {
                if (skip_forced && i == forced_pos)
                    continue;
                if (p[i] == i)
                    continue;
                l = i;
                break;
            }
            if (l == -1)
                return {-1, -1};
            for (int i = n; i >= 1; i--)
            {
                if (skip_forced && i == forced_pos)
                    continue;
                if (p[i] == i)
                    continue;
                r = i;
                break;
            }
            return {l, r};
        };

        if (missing.empty())
        {
            auto pr = compute_lr(false, -1);
            if (pr.first == -1)
                cout << 0 << endl;
            else
                cout << (pr.second - pr.first + 1) << endl;
            continue;
        }

        bool forced_single = (missing.size() == 1 && zeros.size() == 1 && missing[0] == zeros[0]);
        auto pr = compute_lr(forced_single, forced_single ? zeros[0] : -1);
        if (pr.first == -1)
            cout << 0 << endl;
        else
            cout << (pr.second - pr.first + 1) << endl;
    }
    return 0;
}
