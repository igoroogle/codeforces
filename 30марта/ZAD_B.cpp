#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 2000000000000000100;
ll a[100010], t[400010], add[400010];
pair<ll, ll> b[100010];
void build(ll l, ll r, ll v);
void push(ll v);
void update(ll l, ll r, ll v, ll tl, ll tr, ll val);
ll get(ll l, ll r, ll v, ll tl, ll tr);
int main()
{
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    ll n, m, i, ans = 0, val;
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);

    build(1, n, 1);
    cin >> m;
    for (i = 0; i < m; i++)
        scanf("%I64d%I64d", &b[i].first, &b[i].second);

    sort(b, b + m);
    for (i = m - 1; i >= 0; i--)
    {
        val = get(1, n, 1, b[i].first, b[i].second);
        if (val > 0)
        {
            ans++;
            update(1, n, 1, b[i].first, b[i].second, -1);
        }
    }
    cout << m - ans << endl;
}

void build(ll l, ll r, ll v)
{
    ll m;
    if (l == r)
    {
        add[v] = 0;
        t[v] = a[l];
        return;
    }

    m = (l + r) / 2;
    build(l, m, v + v);
    build(m + 1, r, v + v + 1);
    t[v] = min(t[v + v], t[v + v + 1]);
    add[v] = 0;
}

void push(ll v)
{
    add[v + v] += add[v];
    add[v + v + 1] += add[v];
    add[v] = 0;
}

void update(ll l, ll r, ll v, ll tl, ll tr, ll val)
{
    ll m;
    if (tl > tr)
        return;

    if ((tl == l) && (tr == r))
    {
        add[v] += val;
        return;
    }

    m = (l + r) / 2;
    push(v);
    update(l, m, v + v, tl, min(tr, m), val);
    update(m + 1, r, v + v + 1, max(tl, m + 1), tr, val);
    t[v] = min(t[v + v] + add[v + v], t[v + v + 1] + add[v + v + 1]);
}

ll get(ll l, ll r, ll v, ll tl, ll tr)
{
    ll m;
    if (tl > tr)
        return INF;
    if ((tl == l) && (tr == r))
        return t[v] + add[v];
    m = (l + r) / 2;
    return min(get(l, m, v + v, tl, min(tr, m)), get(m + 1, r, v + v + 1, max(tl, m + 1), tr)) + add[v];
}

/*
4
3 4 4 2
4
3 4
4 4
1 1
3 4
*/

/*
6
2 3 6 4 1 4
11
2 5
1 5
2 2
3 3
1 1
3 3
3 5
4 4
2 2
1 6
3 5
*/
