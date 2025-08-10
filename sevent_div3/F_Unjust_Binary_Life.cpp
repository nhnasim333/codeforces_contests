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
        string a, b;
        cin >> a >> b;

        vector<int> pa(n + 1, 0), pb(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pa[i] = pa[i - 1] + (a[i - 1] == '1');
        for (int i = 1; i <= n; i++)
            pb[i] = pb[i - 1] + (b[i - 1] == '1');

        vector<long long> X(n), Y(n);
        for (int i = 0; i < n; i++)
        {
            int x = i + 1;
            X[i] = 2LL * pa[x] - x;
            Y[i] = 2LL * pb[x] - x;
        }

        sort(Y.begin(), Y.end());
        vector<long long> prefixY(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefixY[i] = prefixY[i - 1] + Y[i - 1];

        long long S = 0;
        for (int i = 0; i < n; i++)
        {
            long long Z = X[i];
            int idx = int(lower_bound(Y.begin(), Y.end(), -Z) - Y.begin());
            long long left_sum = (idx > 0) ? prefixY[idx] : 0;
            long long right_sum = prefixY[n] - left_sum;

            long long left_count = idx;
            long long right_count = n - idx;

            long long val = -left_sum - left_count * Z + right_sum + right_count * Z;
            S += val;
        }

        long long total = 1LL * n * n * (n + 1);
        long long ans = (total - S) / 2;
        cout << ans << endl;
    }
    return 0;
}
