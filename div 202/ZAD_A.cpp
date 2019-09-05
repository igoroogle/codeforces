#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, a = 0, b = 0, c = 0, i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 25)
            a++;
        else if (x == 50)
        {
            if (a == 0)
            {
                cout << "NO\n";
                return 0;
            }
            a--;
            b++;
        }
        else
        {
            if ((b > 0) && (a > 0))
            {
                b--;
                a--;
                c++;
            }
            else if (a > 2)
            {
                a -= 3;
                c++;
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}
