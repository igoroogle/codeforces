#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[1000100], kol = 0;
int main()
{
    freopen("frac.in", "r", stdin);
    freopen("frac.out", "w", stdout);
    ll p, q, i;
    cin >> p >> q;
    a[kol++] = p / q;
    p = p - q * a[0];

    while ((q != 0) && ((p % q) || (p / q != 0)))
    {
        swap(q, p);
        a[kol++] = p / q;
        p = p - q * a[kol - 1];
    }

    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%I64d ", a[i]);
    return 0;
}
