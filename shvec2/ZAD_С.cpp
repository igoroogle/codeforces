#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a[100010];
int color[100010], sum[100010], valt[100010], ss = 0, n, m, k;
int dfs(int v);
int main()
{
    int i, x, y;
    cin >> n >> m >> k;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (i = 0; i < n; i++)
        if (!color[i])
            dfs(i);
    return 0;
}

int dfs(int v)
{
    ss++;
    sum[v] = ss;
    valt[ss - 1] = v;
    color[v] = 1;
    int i, j;
    for (i = 0; i < a[v].size(); i++)
    {
        if ((color[a[v][i]] == 1) && (ss - sum[a[v][i]] >= k))
        {
            cout << ss - sum[a[v][i]] + 1 << endl;
            for (j = sum[a[v][i]] - 1; j < ss; j++)
                printf("%d ", valt[j] + 1);
            exit(0);
        }
        else if (!(color[a[v][i]]))
            dfs(a[v][i]);
    }
    color[v] = 2;
}
