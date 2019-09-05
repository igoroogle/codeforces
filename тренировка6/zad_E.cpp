#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define sz(n) n.size()
#define x first
#define y second

typedef long long ll;

ll n;
ll a[200100], d[200100], dp[200100];
vector < pair < ll, ll > > g[200100];
bool mark[200100];

ll dfs(ll v, ll p, ll t)
{
    //cout << v << ' ' << p << ' ' << t << endl;
    ll sum = a[v];
    forn(i, sz(g[v]))
        if (g[v][i].x != p)
        {
            if (!mark[g[v][i].y])
                d[g[v][i].y] = dfs(g[v][i].x, v, g[v][i].y);
            sum += d[g[v][i].y];
        }
    d[t] = sum;
    mark[t] = 1;
    return sum;
}

int main()
{
    freopen("hospital.in", "r", stdin);
    freopen("hospital.out", "w", stdout);
    cin >> n;
    int x, y, k = 0;
    forn(i, n)
        scanf("%I64d", &a[i + 1]);
    forn(i, n - 1)
    {
        scanf("%I64d %I64d", &x, &y);
        k++;
        g[x].pb(mp(y, k));
        k++;
        g[y].pb(mp(x, k));
    }

    for (ll i = 1; i <= n; i++)
        forn(j, sz(g[i]))
        {
            if (!mark[g[i][j].y])
                d[g[i][j].y] = dfs(g[i][j].x, i, g[i][j].y);
            dp[i] = max(dp[i], d[g[i][j].y]);
        }
    ll maxi = 10000000000000000, ind = 0;
    for (ll i = 1; i <= n; i++)
        if (dp[i] < maxi)
    {
        maxi = dp[i];
        ind = i;
    }
    cout << ind;

    return 0;
}

/*

5
3 3 2 5 1
1 2
2 3
2 4
4 5


*/



