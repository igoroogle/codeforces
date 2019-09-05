#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int INF = 2E9;
vector <int> a[300010], b[300010];
int d[300010], r[300010], ans = 1, sans, mxans;
bool use[300010];
void get_ans(int v);
void get_val(int v, int p);
void get_centre(int v, int p, int sum);
void dfs(int v, int p);
int main()
{
    //freopen("alarm.in", "r", stdin);
    //freopen("alarm.out", "w", stdout);
    int n, i, x, y, z;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &r[i]);
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        x--;
        y--;
        a[x].pb(y);
        b[x].pb(z);
        a[y].pb(x);
        b[y].pb(z);
    }
    cout << endl;
    get_ans(0);
    cout << ans << endl;
    return 0;
}

void get_ans(int v)
{
    int i, u;
    get_val(v, -1);
    sans = v;
    mxans = INF;
    get_centre(v, -1, 0);
    u = sans;
    cout << u << ' ' << r[u] << endl;
    dfs(u, -1);
    //cout << u << ' ' << r[u] << endl;
    for (i = 0; i < a[u].size(); i++)
    if (!use[a[u][i]])
    {
        if ((b[u][i] > r[a[u][i]]) && (b[u][i] > r[u]))
            ans++;
        r[a[u][i]] = max(r[a[u][i]], r[u] - b[u][i]);
    }

    use[u] = 1;
    cout << ans << endl;
    for (i = 0; i < a[u].size(); i++)
    if (!use[a[u][i]])
        get_ans(a[u][i]);
}

void get_val(int v, int p)
{
    int i;
    d[v] = 1;
    for (i = 0; i < a[v].size(); i++)
        if ((!use[a[v][i]]) && (a[v][i] != p))
        {
            get_val(a[v][i], v);
            d[v] += d[a[v][i]];
        }
}

void get_centre(int v, int p, int sum)
{
    int mx = sum, sm = sum, i;
    for (i = 0; i < a[v].size(); i++)
    if ((!use[a[v][i]]) && (a[v][i] != p))
    {
        mx = max(mx, d[a[v][i]]);
        sm += d[a[v][i]];
    }

    if (mx < mxans)
    {
        mxans = mx;
        sans = v;
    }

    sm++;
    for (i = 0; i < a[v].size(); i++)
    if ((!use[a[v][i]]) && (a[v][i] != p))
        get_centre(a[v][i], v, sm - d[a[v][i]]);
}

void dfs(int v, int p)
{
    int i;
    for (i = 0; i < a[v].size(); i++)
    if ((!use[a[v][i]]) && (a[v][i] != p))
    {
        dfs(a[v][i], v);
        r[v] = max(r[v], r[a[v][i]] - b[v][i]);
    }
}

/*

10
1 2 2 2 6 3 4 5 4 3
1 2 5
2 3 1
2 4 5
4 5 2
4 6 4
4 7 3
1 8 1
8 9 5
8 10 4

6
4 9 6 4 10 1
1 2 7
2 6 7
2 3 14
6 5 4
6 4 5
*/
