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
const int N = 100001;
const int M = 12001;

ll n, m, s, t, a, b;
ll d[N];
vector < pll > g[N];

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n >> m >> s >> t;
    ll x, y, z;
    forn(i, m)
    {
        scanf("%I64d %I64d %I64d", &x, &y, &z);
        g[x].pb(mp(y, z));
        g[y].pb(mp(x, z));
    }
    cin >> a >> b;
    forn(i, n + 1)
        d[i] = INF64;
    d[s] = 0;
    set < pll > ss;
    ss.insert(mp(0, s));
    while (!ss.empty())
    {
        int u = (*ss.begin()).y;
        ll k = (*ss.begin()).x;
        ss.erase(ss.begin());
        forn(i, sz(g[u]))
        if (d[g[u][i].x] > k + g[u][i].y && g[u][i].y <= a)
        {
            ss.erase(mp(d[g[u][i].x], g[u][i].x));
            d[g[u][i].x] = k + g[u][i].y;
            ss.insert(mp(d[g[u][i].x], g[u][i].x));
        }
    }
    ss.clear();
    for (int i = 1; i <= n; i++)
        if (d[i] != INF64)
            ss.insert(mp(d[i], i));
    while (!ss.empty())
    {
        int u = (*ss.begin()).y;
        ll k = (*ss.begin()).x;
        ss.erase(ss.begin());
        forn(i, sz(g[u]))
        if (d[g[u][i].x] > k + g[u][i].y && g[u][i].y >= b)
        {
            ss.erase(mp(d[g[u][i].x], g[u][i].x));
            d[g[u][i].x] = k + g[u][i].y;
            ss.insert(mp(d[g[u][i].x], g[u][i].x));
        }
    }
    if (d[t] == INF64)
        cout << -1;
    else
    cout << d[t];
    return 0;
}


/*
4 6
1 4
1 2 4
2 4 4
4 1 6
1 3 7
4 3 10
3 2 2
5 6


6 9
2 4
2 6 4
6 4 5
4 5 1
5 3 10
3 2 9
2 5 5
1 5 2
1 6 2
1 2 1
5 3


*/


