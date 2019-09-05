#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long double ld;

const ull MXV = 1000000000;
const ull INF = 2000000000000000100;

ull n, k, n1;

ull change(ull n)
{
    ull k = 0;
    while (1 << (k + 1) <= n)
        k++;

    n -= (1 << k);
    n = (n << 1);
    n++;

    return n;
}

int main()
{
    //freopen("number.in", "r", stdin);
    //freopen("number.out", "w", stdout);

    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    while (1 << (k + 1) <= n)
        k++;
    n1 = n;

    for (int i = 0; i < min(k, n1); i++)
    {
        n = change(n);
        //cout << n << endl;
    }
    cout << n;
    return 0;
}
