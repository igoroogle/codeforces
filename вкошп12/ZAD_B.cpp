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
#define NAME "odd"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 7e18;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979310000;
const ll MD = 535355424;
const ll T = 34539;
const int N = 200101;
const int M = 505;

int n, m, p[N];
vector < int > g[N];
vector < pii > e;
bool mark[N], f[N];

int sum = 0;

void dfs(int v)
{
    mark[v] = 1;
    sum++;
    forn(i, sz(g[v]))
        if (!mark[g[v][i]])
            dfs(g[v][i]);
}

int main()
{
    FREOPEN;
    cin >> n >> m;
    forn(i, m)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
        e.pb(mp(x, y));
        p[x]++;
        p[y]++;
    }

    for (int i = 1; i <= n; i++)
        if (!mark[i])
        {
            sum = 0;
            dfs(i);
            if (sum % 2 != 0)
            {
                cout << -1;
                return 0;
            }
        }
    sum = 0;
    vector < int > ans;
    forn(i, m)
        if (p[e[i].x] % 2 == 0 && p[e[i].y] % 2 == 0)
        {
             p[e[i].x]--;
             p[e[i].y]--;
             f[i] = 1;
             sum++;
        }
    cout << m - sum << endl;
    forn(i, m)
        if (!f[i])
            printf("%d ", i + 1);
    return 0;
}


/*





*/


