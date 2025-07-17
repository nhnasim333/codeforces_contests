#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        for (int y = 0;; y++)
        {
            int tempX = x;
            int tempY = y;
            bool found = false;

            int digitX[10] = {0};

            while (tempX > 0)
            {
                digitX[tempX % 10] = 1;
                tempX /= 10;
            }

            if (y == 0 && digitX[0])
            {
                found = true;
            }

            while (tempY > 0)
            {
                if (digitX[tempY % 10])
                {
                    found = true;
                    break;
                }
                tempY /= 10;
            }

            if (found)
            {
                cout << y << endl;
                break;
            }
        }
    }

    return 0;
}