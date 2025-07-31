#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());
        int sum_direct = 0;
        for (int i = 0; i < n; ++i)
            sum_direct += b[i];
        if (s >= sum_direct)
        {
            cout << -1 << endl;
            continue;
        }
        // If sum of direct path is not s, output sorted
        if (sum_direct != s)
        {
            for (int i = 0; i < n; ++i)
                cout << b[i] << " ";
            cout << endl;
        }
        else
        {
            // Swap last two to avoid sum s in direct path
            swap(b[n - 2], b[n - 1]);
            for (int i = 0; i < n; ++i)
                cout << b[i] << " ";
            cout << endl;
        }
    }
    return 0;
}