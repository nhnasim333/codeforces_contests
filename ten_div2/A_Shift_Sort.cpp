#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int cnt0 = count(s.begin(), s.end(), '0');
        int misplaced1 = 0;
        for (int i = 0; i < cnt0; ++i)
        {
            if (s[i] == '1')
                misplaced1++;
        }
        int misplaced0 = 0;
        for (int i = cnt0; i < n; ++i)
        {
            if (s[i] == '0')
                misplaced0++;
        }

        if (misplaced1 == 0 && misplaced0 == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << max(misplaced1, misplaced0) << endl;
        }
    }
    return 0;
}