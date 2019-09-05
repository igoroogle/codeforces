#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void build(ll v, ll l, ll r);
ll get(ll v, ll l, ll r, ll tl, ll tr);
ll t[400040], a[100010], rig[100010];
map <ll, ll> b;
int main()
{
    freopen("bumblebee.in", "r", stdin);
    freopen("bumblebee.out", "w", stdout);
    ll n, m, i, l, r, val1, val2, val;
    cin >> n;
    for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a[i]++;
        }
    rig[n] = n + 1;
    b[a[n]] = n;
    for (i = n - 1; i >= 1; i--)
    {
        val1 = b[a[i] + 2];
        val2 = b[a[i] - 2];
        if (val1 == 0)
            val1 = n + 1;
        if (val2 == 0)
            val2 = n + 1;
        val = min(val1, val2);
        rig[i] = min(rig[i + 1], val - 1);
        b[a[i]] = i;
    }
    build(1, 1, n);
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        val = get(1, 1, n, l, r);
        if (rig[l] < r)
            val = 1;
        printf("%d\n", val);
    }
    return 0;
}

void build(ll v, ll l, ll r)
{
    ll m;
    if (l == r)
    {
        t[v] = a[l];
        return;
    }
    m = (l + r) / 2;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    t[v] = gcd(t[v + v], t[v + v + 1]);
}

ll get(ll v, ll l, ll r, ll tl, ll tr)
{
    ll m;
    if (tl > tr)
        return 0;
    if ((tl == l) && (tr == r))
        return t[v];
    m = (l + r) / 2;
    return gcd(get(v + v, l, m, tl, min(tr, m)), get(v + v + 1, m + 1, r, max(tl, m + 1), tr));
}
