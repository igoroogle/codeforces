#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("steak.in", "r", stdin);
    freopen("steak.out", "w", stdout);
    ll k, ans = 0, val = 30, n, sm = 0, a0 = 30, an;
    cin >> k;
    n = k / 5;
    an = n * 30;
    k = k % 5;
    if (n > 0)
        sm = ll(double(a0 + an) / 2.0 * double(n)) * ll(5);
    sm += k * ll(n * 30 + 30);
    cout << sm << endl;
    return 0;
}
