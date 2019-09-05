#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
vector<int> a[100010];
int color[100010];
int dfs(int v, int p);
int main()
{
    int n, m, i, u, v, ans = 0;
    cin >> n >> m;
    while (m--)
    {
        scanf("%d%d", &u, &v);
        u--;
        v--;
        a[u].pb(v);
        a[v].pb(u);
    }

    for (i = 0; i < n; i++)
        if ((!color[i]) && (dfs(i, -1) == 1))
            ans++;

    cout << ans << endl;
    return 0;
}

int dfs(int v, int p)
{
    color[v] = 1;
    int i;
    int f = 1, ff;
    for (i = 0; i < a[v].size(); i++)
    if (a[v][i] != p)
    {
        if (color[a[v][i]] == 1)
        {
            f = 2;
            continue;
        }

        if (!color[a[v][i]])
        {
            ff = dfs(a[v][i], v);
            if (ff == 2)
                f = 2;
        }
    }
    color[v] = 2;

    if (f == 2)
        return 2;
    return 1;
}
