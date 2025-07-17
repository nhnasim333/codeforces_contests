#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int y = 0;
        while (x > 0)
        {
            int digit = x % 10;
            if (y == 0 || digit < y)
            {
                y = digit;
            }
            x /= 10;
        }
        cout << y << endl;
    }
    return 0;
}