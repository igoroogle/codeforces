#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
const ll INF = 1000000000;
const ll INF2 = 2000000000000000004;
pair<ll, ll> ans[4000100];
ll t[4000100], kl = 0;
ll binp(ll x, ll n);
ll fun(ll n, ll m);
int main()
{
    ll s = 0, cnt = 0, i, vl, x, cnt2 = 0;
    cin >> x;
    while (s < INF2)
    {
        kl++;
        s += kl * kl;
        t[kl] = s;
    }
    cout << binp(x, 275) << endl;
    for (i = 1; i < 300000; i++)
    {
        vl = binp(x, i);
        if (fun(i, vl) != x)
            continue;
        ans[cnt++] = mp(i, vl);
    }

    cnt2 = cnt;
    for (i = 0; i < cnt; i++)
        ans[cnt2++] = mp(ans[i].y, ans[i].x);
    cnt = 1;
    sort(ans, ans + cnt2);
    for (i = 1; i < cnt2; i++)
        if (ans[i] != ans[i - 1])
            ans[cnt++] = ans[i];
    cout << cnt << endl;
    for (i = 0; i < cnt; i++)
        printf("%I64d %I64d\n", ans[i].x, ans[i].y);
    return 0;
}

ll fun(ll n, ll m)
{
    ll tt = ll(sqrt(ld(n))) * ll(sqrt(ld(m)));
    if (tt > INF)
        return INF2;
    ll k, y, ans;
    if (n < m)
        swap(n, m);
    k = m;
    if ((k > kl) || (n * m > 1E18))
        return INF2;
    y = n - m;
    ans = k * (n * n - n * y);
    ans += ll(ld(k - 1) / ld(2) * ld(k)) * (y - n - n);
    ans += t[k - 1];
    if ((ans > INF2) || (ans < 0))
        ans = INF2;
    return ans;
}

ll binp(ll x, ll n)
{
    ll m, l, r;
    l = 1;
    r = x + ll(1);
    while (l < r)
    {
        m = (l + r) >> ll(1);
        if (fun(n, m) < x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}
