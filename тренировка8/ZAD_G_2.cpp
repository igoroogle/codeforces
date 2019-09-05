#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long double ld;
ull n;
const ull MXV = 1000000000;
const ull INF = 2000000000000000100;
ull ans[1000100], st[1000100], kol = 0;
ull step(ull a, ull n)
{
    ull i, ans = 1;
    for (i = 1; i <= n; i++)
    {
        if (ull(sqrt(ld(ans))) * ull(sqrt(ld(a))) > MXV)
            return INF;
        ans *= a;
    }
    return ans;
}

void binp(ull x, ull y)
{
    ull l = 0, r = x, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (step(m, y) < x)
            l = m + 1;
        else
            r = m;
    }

   if (step(l, y) == x)
   {
       ans[kol] = l;
       st[kol++] = y;
   }
}
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    ull x, i;
    cin >> x;
    for (i = 60; i >= 2; i--)
        binp(x, i);
    cout << kol << endl;
    for (i = 0; i < kol; i++)
        cout << ans[i] << ' ' << st[i] << endl;
}
