#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353;

bool is_sorted(const vector<int> &a, const vector<int> &b, const vector<bool> &swap)
{
    int n = a.size();
    int prev_a = -1, prev_b = -1;
    for (int i = 0; i < n; ++i)
    {
        int ai = swap[i] ? b[i] : a[i];
        int bi = swap[i] ? a[i] : b[i];
        if (ai < prev_a || bi < prev_b)
            return false;
        prev_a = ai;
        prev_b = bi;
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
        vector<int> a(n), b(n);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int prev = 0; prev <= 1; ++prev)
            {
                int prev_a = prev ? b[i - 1] : a[i - 1];
                int prev_b = prev ? a[i - 1] : b[i - 1];
                int now_a = a[i], now_b = b[i];
                if (prev_a <= now_a && prev_b <= now_b)
                    dp[i][0] = (dp[i][0] + dp[i - 1][prev]) % MOD;
                now_a = b[i];
                now_b = a[i];
                if (prev_a <= now_a && prev_b <= now_b)
                    dp[i][1] = (dp[i][1] + dp[i - 1][prev]) % MOD;
            }
        }
        int ans = (dp[n - 1][0] + dp[n - 1][1]) % MOD;
        cout << ans << endl;
    }
    return 0;
}