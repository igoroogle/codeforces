#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> ed[100010], ans[2];
int color[100010];
int dfs(int v, int t);
int main()
{
    int n, m, i, x, y;
    cin >> n >> m;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        ed[x].pb(y);
        ed[y].pb(x);
    }

    for (i = 0; i < n; i++)
        if (!use[i])
            dfs(i, 0);

    cout <<
    return 0;
}

int dfs(int v, int t)
{
    ans[t].pb(v);
    color[v] = t + 1;
    for (int i = 0; i < a[v].size(); i++)
    {
        if ((color[a[v][i]]) && (color[a[v][i]] == color[v]))
        {
            cout << -1 << endl;
            exit(0);
        }
        else if (!color[a[v][i]])
            dfs(a[v][i], 1 - t);
    }

}
