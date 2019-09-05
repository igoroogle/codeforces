#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "dwarfs"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const ll INF64 = 7e18;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979310000;
const ll MD = 535355424;
const ll T = 34539;
const int N = 200100;
const int M = 301;

int n, s, f, tin[N], tout[N], timer = 0, d[N];
vector < int > g[N];
bool mark[N];
int maxi = 0;
vector < int > a;

int dfs1(int v)
{
    mark[v] = 1;
    tin[v] = timer++;
    d[v] = 1;

    forn(i, sz(g[v]))
        if (!mark[g[v][i]])
            d[v] += dfs1(g[v][i]);

    tout[v] = timer++;
    return d[v];
}

bool get(int a, int b)
{
    return (tin[a] <= tin[b] && tout[a] >= tin[b]);
}

void dfs(int v)
{
    mark[v] = 1;

    if ((int)get(v, s) + (int)get(v, f) == 1)
        maxi = max(maxi, min(d[v], n - d[v]));

    forn(i, sz(g[v]))
        if (!mark[g[v][i]])
            dfs(g[v][i]);


}

int main()
{
    //Freopen;
    FREOPEN;
    cin >> n;
    forn(i, n - 1)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    if (n == 2)
    {
        cout << 1;
        return 0;
    }
    cin >> s >> f;
    int vv;
    for (int i = 1; i <= n; i++)
        if (i != s && i != f)
        {
            vv = i;
            break;
        }
    dfs1(vv);
    forn(i, N)
        mark[i] = 0;

    dfs(vv);


    cout << maxi;
    return 0;
}



/*

6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8



*/

