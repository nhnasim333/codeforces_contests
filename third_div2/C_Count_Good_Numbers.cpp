#include <bits/stdc++.h>
using namespace std;

long long count_good(long long x)
{
    int primes[] = {2, 3, 5, 7};
    long long res = x;
    for (int mask = 1; mask < 16; ++mask)
    {
        long long prod = 1;
        int bits = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (mask & (1 << i))
            {
                prod *= primes[i];
                bits++;
            }
        }
        long long cnt = x / prod;
        if (bits % 2 == 1)
            res -= cnt;
        else
            res += cnt;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        long long good_count = count_good(r) - count_good(l - 1);
        cout << good_count << endl;
    }
    return 0;
}