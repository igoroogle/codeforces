#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const int MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const int N = 300001;
const int M = 12001;

ll a[N], t[N * 8], t1[N * 8], t2[N * 8], n, m;

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        scanf("%I64d", &t[v]);
        t1[v] = t[v];
        t2[v] = t[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
        t1[v] = t1[v * 2] + t1[v * 2 + 1];
        t2[v] = min(t2[v * 2], t2[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int ind, ll pos)
{
    if (tl == tr)
    {
        t[v] = pos;
        t1[v] = pos;
        t2[v] = pos;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (ind <= tm)
            update(v * 2, tl, tm, ind, pos);
        else
            update(v * 2 + 1, tm + 1, tr, ind, pos);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
        t1[v] = t1[v * 2] + t1[v * 2 + 1];
        t2[v] = min(t2[v * 2], t2[v * 2 + 1]);
    }
}

ll maxi(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return -INF;
    else
        if (tl == l && tr == r)
            return t[v];
        else
        {
            int tm = (tl + tr) / 2;
            return max(maxi(v * 2, tl, tm, l, min(r, tm)), maxi(v  * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }
}


ll mini(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return INF;
    else
        if (tl == l && tr == r)
            return t2[v];
        else
        {
            int tm = (tl + tr) / 2;
            return min(mini(v * 2, tl, tm, l, min(r, tm)),mini(v  * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }
}

ll sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    else
        if (tl == l && tr == r)
            return t1[v];
        else
        {
            int tm = (tl + tr) / 2;
            return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v  * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        }
}

int main()
{
    freopen("hel.in", "r", stdin);
    freopen("hel.out", "w", stdout);
    cin >> n;
    build(1, 1, n);
    cin >> m;
    string s;
    ll x, y, z;
    forn(u, m)
    {
        cin >> s;
        if (s == "assign")
        {
            scanf("%I64d %I64d", &x, &y);
            update(1, 1, n, x, y);
        }
        else
        {
            scanf("%I64d %I64d %I64d", &x, &y, &z);
            ll q = maxi(1, 1, n, x, y);
            if (z <= 0)
                q = mini(1, 1, n, x, y);
            printf("%I64d\n", (sum(1, 1, n, x, y) - q) + q  * z);
        }
    }
    return 0;
}

/*
6
-1  -6  0  5   3    -3
9
assign    1        -9
torture    1        1        7
assign      2        9
torture      1           2       -9
torture       3           5        -6
torture       3           6        0
assign       3           -1
torture       5       6        9
torture         6           6 0

*/




