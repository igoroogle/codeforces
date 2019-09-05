#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
const ll N = 100004;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void build(ll v, ll l, ll r);
void get(ll v, ll l, ll r, ll tl, ll tr, ll &ans, ll &indx);
void update(ll v, ll l, ll r, ll ind, ll val, ll indx);
void rec(ll sum, ll indx);
ll t[400040], t2[400040], a[100010], tim[100010], dp[100010], past[100010], ind[100010];
int main()
{
    freopen("assault.in", "r", stdin);
    freopen("assault.out", "w", stdout);
    ll n, m, i, l, r, val, indx, val2, indx2;
    for (i = 0; i <= N; i++)
        past[i] = -1;
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &tim[i]);
    dp[0] = 0;
    for (i = 1; i <= n; i++)
    {
        if (tim[i] > 1)
            get(1, 1, N, 1, tim[i] - 1, val, indx);
        else
            {
                val = 0;
                indx = 0;
            }
        if (indx == 0)
            val = 0;
        if (a[i] + dp[tim[indx]] > dp[tim[i]])
        {
            dp[tim[i]] = a[i] + dp[tim[indx]];
            ind[tim[i]] = i;
            past[i] = indx;
            update(1, 1, N, tim[i], dp[tim[i]], i);
            get(1, 1, N, tim[i], tim[i], val, indx);
        }
    }
    ll mx = 0, vl = 0;
    for (i = 1; i <= N; i++)
        if (dp[i] > mx)
        {
            mx = dp[i];
            vl = ind[i];
        }
    cout << mx << endl;
    rec(1, vl);
    return 0;
}

void get(ll v, ll l, ll r, ll tl, ll tr, ll &ans, ll &indx)
{
    ll m, val1, ind1, val2, ind2;
    if (tl > tr)
        {
            ans = -INF;
            indx = 0;
            return;
        }
    if ((tl == l) && (tr == r))
    {
        ans = t[v];
        indx = t2[v];
        return;
    }

    m = (l + r) / 2;
    get(v + v, l, m, tl, min(tr, m), val1, ind1);
    get(v + v + 1, m + 1, r, max(tl, m + 1), tr, val2, ind2);
    if (val1 >= val2)
    {
        ans = val1;
        indx = ind1;
    }
    else
    {
        ans = val2;
        indx = ind2;
    }
    return;
}

void update(ll v, ll l, ll r, ll ind, ll val, ll indx)
{
    ll m;
    if (l == r)
    {
        t[v] = val;
        t2[v] = indx;
        return;
    }

    m = (l + r) / 2;
    if (ind <= m)
        update(v + v, l, m, ind, val, indx);
    else
        update(v + v + 1, m + 1, r, ind, val, indx);
    if (t[v + v] >= t[v + v + 1])
    {
        t[v] = t[v + v];
        t2[v] = t2[v + v];
    }
    else
    {
        t[v] = t[v + v + 1];
        t2[v] = t2[v + v + 1];
    }
    return;
}

void rec(ll sum, ll indx)
{
    if (past[indx] < 1)
        cout << sum << endl;
    else
        rec(sum + 1, past[indx]);
    if (sum == 1)
        printf("%I64d\n", indx);
    else
        printf("%I64d ", indx);
}
/*
3
1 2 1
1 2 3
*/
