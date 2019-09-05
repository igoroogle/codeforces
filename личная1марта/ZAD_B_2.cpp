#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void build(ll v, ll l, ll r);
ll get(ll v, ll l, ll r, ll tl, ll tr);
void update(ll v, ll l, ll r, ll ind, ll val);
ll t[400040], a[100010];
int main()
{
    //freopen("bumblebee.in", "r", stdin);
    //freopen("bumblebee.out", "w", stdout);
    ll n, m, i, l, r;
    cin >> n;
    for (i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
            a[i]++;
        }

    build(1, 1, n);
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", get(1, 1, n, l, r));
    }
    return 0;
}

void build(ll v, ll l, ll r)
{
    ll m;
    if (l == r)
    {
        t[v] = INF;
        return;
    }
    m = (l + r) / 2;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    t[v] = min(t[v + v], t[v + v + 1]);
}

ll get(ll v, ll l, ll r, ll tl, ll tr)
{
    ll m;
    if (tl > tr)
        return INF;
    if ((tl == l) && (tr == r))
        return t[v];
    m = (l + r) / 2;
    return min(get(v + v, l, m, tl, min(tr, m)), get(v + v + 1, m + 1, r, max(tl, m + 1), tr));
}

void update(ll v, ll l, ll r, ll ind, ll val)
{
    ll m;
    if (l == r)
    {
        t[v] = val;
        return;
    }

    m = (l + r) / 2;
    if (m <= ind)
        update(v + v, l, m, ind, val);
    else
        update(v + v + 1, l, m, ind, val);
    t[v] = min(t[v + v], t[v + v + 1]);
    return;
}
