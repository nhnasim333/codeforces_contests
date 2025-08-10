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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int iterations = 0;
        while (true)
        {
            bool decreased = false, increased = false;
            for (int i = 0; i < n; i++)
            {
                if (!decreased && a[i] > b[i])
                {
                    a[i]--;
                    decreased = true;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (!increased && a[i] < b[i])
                {
                    a[i]++;
                    increased = true;
                }
            }
            iterations++;
            if (!decreased)
                break;
        }
        cout << iterations << endl;
    }
    return 0;
}