#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long double ld;

const ull MXV = 1000000000;
const ull INF = 2000000000000000100;

ull n, k, n1;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> n;
    while (n > 0)
    {
        k += (n % 2);
        n /= 2;
    }

    cout << ull((ull(1) << ull(k)) - ull(1));

    return 0;
}
