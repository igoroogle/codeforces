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
const int N = 300100;
const int M = 301;
typedef long long ll;
int n, st = 0, par[200010], u0, v0, uu, vv, d[200010], ans1[200010], ans2[200010], t = 0;
bool use[200010];
vector <int> a[200010];
void dfs(int u, int p);
int rec(int u, int p);
int main()
{
    FREOPEN;
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

    if (u0 == v0)
    {
        cout << 0 << endl;
        return 0;
    }

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
    ans1[0] = rec(d[0], -1) + 1;
    for (i = 1; i < t - 1; i++)
        ans1[i] = max(rec(d[i], -1) + i + 1, ans1[i - 1]);
    ans2[t - 1] = rec(d[t - 1], - 1) + 1;
    for (i = t - 2; i > 0; i--)
        ans2[i] = max(rec(d[i], -1) + t - i, ans2[i + 1]);
    for (i = 0; i < t - 1; i++)
        ans = max(ans, min(ans1[i], ans2[i + 1]));
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
            s = max(rec(a[u][i], u) + 1, s);
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
