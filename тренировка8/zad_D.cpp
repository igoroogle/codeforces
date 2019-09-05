#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long double ld;

const ull MXV = 1000000000;
const ull INF = 2000000000000000100;

ull n, res;

int main()
{
    freopen("circles2.in", "r", stdin);
    freopen("circles2.out", "w", stdout);

    cin >> n;

    if (n == 0)
        cout << 1;
    else if (n == 1)
        cout << 2;
    else if (n == 2)
        cout << 4;
    else if (n == 3)
        cout << 8;
    else
    {
        res = 8;
        for (ull i = 4; i <= n; i++)
            res += 6 + 2 * (i - 4);
        cout << res;
    }
    return 0;
}
