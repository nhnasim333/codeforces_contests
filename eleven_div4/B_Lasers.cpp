#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long x, y;
        cin >> n >> m >> x >> y;
        for (int i = 0; i < n; i++)
        {
            long long ai;
            cin >> ai;
        }
        for (int j = 0; j < m; j++)
        {
            long long bj;
            cin >> bj;
        }
        cout << (long long)n + m << endl;
    }
    return 0;
}