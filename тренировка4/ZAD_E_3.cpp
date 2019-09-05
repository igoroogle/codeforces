#include <bits/stdc++.h>

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

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const ll MD = 1248742437;
const ll T = 378531;
const int N = 200001;
const int M = 100000;

int n, m, k;
vector < pii > g[100];
bool d[N], mark[N];

bool dfs(int v)
{
    if (mark[v])
        return d[v];
    mark[v] = 1;
    if (v == n)
        return d[v] = 1;
    int x = 0;
    forn(i, sz(g[v]))
        if (dfs(g[v][i].x))
            x++;
    if (x > k)
        return d[v] = 1;
    else
        return d[v] = 0;
}

int main()
{
    //freopen("reading.in", "r", stdin);
    //freopen("reading.out", "w", stdout);
    cin >> n >> m >> k;
    int x, y;
    forn(i, m)
    {
        cin >> x >> y;
        g[x].pb(mp(y, i + 1));
    }

    for (int i = 1; i <= n; i++)
        if (!mark[i])
            d[i] = dfs(i);

    if (d[1])
    {
        cout << "NO";
        fflush(stdout);
        return 0;
    }

    int v = 1;

    while (v != -1)
    {
        vector < int > ans;
        ans.clear();
        forn(i, sz(g[v]))
            if (d[g[v][i].x])
                ans.pb(g[v][i].y);
        cout << sz(ans) << ' ';
        forn(i, sz(ans))
            if (i < sz(ans) - 1)
                cout << ans[i] << ' ';
            else
                cout << ans[i] << endl;
        fflush(stdout);
        cin >> v;
    }
    return 0;
}


/*
4 4 2
1 2
1 3
2 4
3 4


4 4 2
1 2
1 3
2 4
3 4


*/
