#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> a[100010], ans[2];
int color[100010];
void dfs(int v, int t);
bool f;
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
    {
        if ((!color[i]) && (a[i].size() > 0))
        {
            f = 0;
            dfs(i, 0);
            if (f)
            {
                ans[0].clear();
                ans[1].clear();
            }
            else
                break;
        }

        if (i == n - 1)
            {
                cout << -1 << endl;
                return 0;
            }
    }

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

void dfs(int v, int t)
{
    ans[t].pb(v);
    color[v] = t + 1;
    for (int i = 0; i < a[v].size(); i++)
    {
        if (f)
            return;

        if ((color[a[v][i]]) && (color[a[v][i]] == color[v]))
        {
            f = 1;
            return;
        }
        else if (!color[a[v][i]])
            dfs(a[v][i], 1 - t);
    }

}
