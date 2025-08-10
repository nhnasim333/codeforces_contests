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
        vector<unsigned int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        bool ok = true;
        for (int i = 0; i < n - 1; ++i)
        {
            if (b[i] != a[i] && b[i] != (a[i] ^ a[i + 1]))
            {
                ok = false;
                break;
            }
        }
        if (b[n - 1] != a[n - 1])
            ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}