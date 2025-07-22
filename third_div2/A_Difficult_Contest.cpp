#include <bits/stdc++.h>
using namespace std;

bool isDifficult(const string &s)
{
    return s.find("FFT") != string::npos || s.find("NTT") != string::npos;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (!isDifficult(s)) {
            cout << s << endl;
            continue;
        }

        int cnt[26] = {0};
        for (char c : s)
            cnt[c - 'A']++;

        string result = "";

        for (int i = 0; i < 26; ++i)
        {
            if (i != ('F' - 'A') && i != ('T' - 'A') && i != ('N' - 'A'))
            {
                result += string(cnt[i], 'A' + i);
            }
        }

        result += string(cnt['T' - 'A'], 'T');
        result += string(cnt['F' - 'A'], 'F');
        result += string(cnt['N' - 'A'], 'N');

        cout << result << endl;
    }
    return 0;
}