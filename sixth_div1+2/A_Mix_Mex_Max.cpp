#include <bits/stdc++.h>
using namespace std;

bool is_good(const vector<int> &a)
{
    int n = a.size();
    vector<int> b(a);
    for (int fill = 0; fill <= 100; ++fill)
    {
        bool consistent = true;
        for (int i = 0; i < n; ++i)
        {
            if (b[i] != -1 && b[i] != fill)
                consistent = false;
        }
        if (!consistent)
            continue;
        bool ok = true;
        for (int i = 0; i <= n - 3; ++i)
        {
            int x = fill, y = fill, z = fill;
            int ai = (b[i] == -1 ? fill : b[i]);
            int aj = (b[i + 1] == -1 ? fill : b[i + 1]);
            int ak = (b[i + 2] == -1 ? fill : b[i + 2]);
            vector<int> t = {ai, aj, ak};
            int mx = max({ai, aj, ak});
            int mn = min({ai, aj, ak});
            bool has0 = false, has1 = false, has2 = false;
            for (int v : t)
                if (v == 0)
                    has0 = true;
            for (int v : t)
                if (v == 1)
                    has1 = true;
            for (int v : t)
                if (v == 2)
                    has2 = true;
            int mex = 0;
            while (find(t.begin(), t.end(), mex) != t.end())
                ++mex;
            if (mex != mx - mn)
                ok = false;
        }
        if (ok)
            return true;
    }
    for (int x = 0; x <= 1; ++x)
    {
        bool ok = true;
        for (int i = 0; i <= n - 3; ++i)
        {
            vector<int> t(3);
            for (int j = 0; j < 3; ++j)
            {
                if (b[i + j] != -1)
                    t[j] = b[i + j];
                else
                    t[j] = ((i + j) % 2 == 0) ? x : (1 - x);
            }
            int mx = max({t[0], t[1], t[2]});
            int mn = min({t[0], t[1], t[2]});
            int mex = 0;
            while (find(t.begin(), t.end(), mex) != t.end())
                ++mex;
            if (mex != mx - mn)
                ok = false;
        }
        if (ok)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (is_good(a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}