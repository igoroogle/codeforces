#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
ll t1[800021], t2[800021], val[200010], nn;

void build1(ll v, ll l, ll r)
{
    ll m;
    if (l == r)
    {
        if (l == 1) t1[v] = 1;
        else if (l == nn) t1[v] = nn;
        else t1[v] = -INF;
        return;
    }
    m = (l + r) / 2;
    build1(v + v, l, m);
    build1(v + v + 1, m + 1, r);
    t1[v] = max(t1[v + v], t1[v + v + 1]);
}

ll get1(ll v, ll l, ll r, ll tl, ll tr)
{
    ll m;
    if (tl > tr) return -INF;
    if ((tl == l) && (tr == r)) return t1[v];
    m = (l + r) / 2;
    return max(get1(v + v, l, m, tl, min(tr, m)), get1(v + v + 1, m + 1, r, max(tl, m + 1), tr));
}

void update1(ll v, ll l, ll r, ll ind, ll val)
{
    ll m;
    if (l == r)
    {
        t1[v] = val;
        return;
    }
    m = (l + r) / 2;
    if (ind <= m) update1(v + v, l, m, ind, val);
    else update1(v + v + 1, m + 1, r, ind, val);
    t1[v] = max(t1[v + v], t1[v + v + 1]);
}

void build2(ll v, ll l, ll r)
{
    ll m;
    if (l == r)
    {
        if (l == 1) t2[v] = 1;
        else if (l == nn) t2[v] = nn;
        else t2[v] = INF;
        return;
    }
    m = (l + r) / 2;
    build2(v + v, l, m);
    build2(v + v + 1, m + 1, r);
    t2[v] = min(t2[v + v], t2[v + v + 1]);
}

ll get2(ll v, ll l, ll r, ll tl, ll tr)
{
    ll m;
    if (tl > tr) return INF;
    if ((tl == l) && (tr == r)) return t2[v];
    m = (l + r) / 2;
    return min(get2(v + v, l, m, tl, min(tr, m)), get2(v + v + 1, m + 1, r, max(tl, m + 1), tr));
}

void update2(ll v, ll l, ll r, ll ind, ll val)
{
    ll m;
    if (l == r)
    {
        t2[v] = val;
        return;
    }
    m = (l + r) / 2;
    if (ind <= m) update2(v + v, l, m, ind, val);
    else update2(v + v + 1, m + 1, r, ind, val);
    t2[v] = min(t2[v + v], t2[v + v + 1]);
}
int main()
{
    ll n, k, a, m, sum, i, x, l, r;
    cin >> n >> a >> k >> m;
    nn = n + 2;
    build1(1, 1, nn);
    build2(1, 1, nn);
    val[0] = 0;

    for (i = 1; i <= n; i++)
    {
        val[i] = 0;
        if (i - k >= 0)
        {
            val[i] = 1;
            val[i] += (i - k) / (k + 1);
        }
    }

    sum = val[n];
    for (i = 0; i < m; i++)
    {
        scanf("%I64d", &x);
        x++;
        l = get1(1, 1, nn, 1, x);
        r = get2(1, 1, nn, x, nn);
        if (r - l - 1 > 0) sum = sum - val[r - l - 1];
        if (x - l - 1 > 0) sum = sum + val[x - l - 1];
        if (r - x - 1 > 0) sum = sum + val[r - x - 1];
        if (sum < a)
        {
            cout << i + 1 << endl;
            return 0;
        }
        update1(1, 1, nn, x, x);
        update2(1, 1, nn, x, x);
    }
    cout << -1 << endl;
    return 0;
}
