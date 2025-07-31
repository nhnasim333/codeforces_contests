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
        vector<int> S(n);
        vector<int> freq(52, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> S[i];
            freq[S[i]]++;
        }
        int score = 0;
        for (int mex = 1; mex <= 51; ++mex)
        {
            int min_freq = INT_MAX;
            for (int i = 0; i < mex; ++i)
                min_freq = min(min_freq, freq[i]);
            if (min_freq == 0)
                break;
            score += mex * min_freq;
            for (int i = 0; i < mex; ++i)
                freq[i] -= min_freq;
        }
        for (int i = 0; i <= 50; ++i)
            score += freq[i] * i;
        cout << score << endl;
    }
    return 0;
}