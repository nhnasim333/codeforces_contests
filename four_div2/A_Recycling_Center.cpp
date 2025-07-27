#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long c;
        cin >> n >> c;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int coins = 0;
        for (int step = 0; step < n; ++step)
        {
            int idx = -1;
            long long max_val = -1;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] != -1 && a[i] <= c && a[i] > max_val)
                {
                    idx = i;
                    max_val = a[i];
                }
            }
            if (idx != -1)
            {
                a[idx] = -1;
            }
            else
            {
                for (int i = 0; i < n; ++i)
                {
                    if (a[i] != -1)
                    {
                        a[i] = -1;
                        coins++;
                        break;
                    }
                }
            }
            for (int i = 0; i < n; ++i)
                if (a[i] != -1)
                    a[i] *= 2;
        }
        cout << coins << endl;
    }
    return 0;
}