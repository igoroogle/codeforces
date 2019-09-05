#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;

int main()
{
    cin >> n >> m;

    cout << 1 << ' ' << 2 << endl;
    fflush(stdout);
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> y;
        if (x != i || y != 1)
        {
            cout << i << ' ' << 1 << endl;
            fflush(stdout);
            break;
        }
        else
        {
            cout << i << ' ' << 2 << endl;
            fflush(stdout);
        }
    }
    cin >> x >> y;
    cout << "x_X\n";
    fflush(stdout);
    return 0;
}
