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
#define NAME "fence"
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
const int N = 300100;
const int M = 301;
typedef long long ll;
int n, st = 0, par[100010], u0, v0, uu, vv, d[100010], zr[100010], t = 0;
bool use[100010];
vector <int> a[100010];
void dfs(int u, int p);
int rec(int u, int p);
int main()
{
    //FREOPEN;
    int i, u, v, ans = 0;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        u--;
        v--;
        a[u].pb(v);
        a[v].pb(u);
    }
    cin >> u0 >> v0;
    u0--;
    v0--;
    dfs(u0, -1);
    i = v0;
    d[t++] = v0;

    while (par[i] != u0)
    {
        st++;
        i = par[i];
        use[i] = 1;
        d[t++] = i;
    }

    d[t++] = u0;
    use[u0] = 1;
    use[v0] = 1;
    uu = rec(u0, -1);
    vv = rec(v0, -1);
    ans = st;
    ans = max(ans, min(st, uu) * 2);
    ans = max(ans, min(st, vv) * 2);
    ans = max(ans, min(uu, vv) * 2);
    cout << ans << endl;
    return 0;
}

void dfs(int u, int p)
{
    int i;
    par[u] = p;
    for (i = 0; i < a[u].size(); i++)
        if (a[u][i] != p)
            dfs(a[u][i], u);
}

int rec(int u, int p)
{
    int i, s = 0;
    for (i = 0; i < a[u].size(); i++)
        if ((a[u][i] != p) && (!use[a[u][i]]))
            s += rec(a[u][i], u) + 1;
    return s;
}


/*
6
1 2
2 3
3 4
4 5
5 6
4 5
*/

/*
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
