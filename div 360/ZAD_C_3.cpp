#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> a[100010], ans[2];
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
        a[x].pb(y);
        a[y].pb(x);
    }

    for (i = 0; i < n; i++)
        if (!color[i])
            dfs(i, 0);

    cout << ans[0].size() << endl;
    for (i = 0; i < ans[0].size() - 1; i++)
        printf("%d ", ans[0][i] + 1);

    cout << ans[0][ans[0].size() - 1] + 1 << endl;

    cout << ans[1].size() << endl;
    for (i = 0; i < ans[1].size() - 1; i++)
        printf("%d ", ans[1][i] + 1);

    cout << ans[1][ans[1].size() - 1] + 1 << endl;
    return 0;
}

int dfs(int v, int t)
{
    if (a[v].size() == 0)
        {
            cout << -1 << endl;
            exit(0);
        }

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
