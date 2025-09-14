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
        vector<long long> a(n);
        long long sum = 0;
        vector<long long> odds;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            if (x % 2)
                odds.push_back(x);
        }

        if (odds.empty())
        {
            cout << 0 << endl;
            continue;
        }
        sort(odds.begin(), odds.end());
        int remove = odds.size() / 2;
        long long sub = 0;
        for (int i = 0; i < remove; i++)
            sub += odds[i];
        cout << (sum - sub) << endl;
    }
    return 0;
}