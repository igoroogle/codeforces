#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long double ld;
const ull INF = 2449489744;
ull gcd(ull a, ull b);
int main()
{
    ull t, w, b, nd, nk, fr, ls, ans = 0, vl, p, q;
    cin >> t >> w >> b;
    if (w > b)
        swap(w, b);
    nd = gcd(w, b);
    fr = w / nd;
    ls = b;
    if (ull(sqrt(ld(fr))) * ull(sqrt(ld(ls))) > INF)
        ans = min(w - 1, t);
    else
    {
        nk = fr * ls;
        vl = t / nk;
        ans = vl;
        ans += min(w - 1, t % nk);
        ans += vl * (w - 1);
    }

    if (ans > 0)
    {
        nd = gcd(ans, t);
        ans /= nd;
        t /= nd;
    }
    else
        t = 1;

    cout << ans << '/' << t << endl;
    return 0;
}

ull gcd(ull a, ull b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
