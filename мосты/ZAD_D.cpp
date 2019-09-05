#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 200010;
vector<int> a[DL];
int tin[DL], fup[DL], ans[DL], child[DL], sum = 0;
bool use[DL], use2[DL];
void dfs(int v, int p);
int main()
{
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    int n, m, x, y, kol = 0, i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (i = 0; i < n; i++)
        if (!use[i])
            {
                dfs(i, -1);
                if (child[i] > 1)
                    use2[i] = 1;
                else
                    use2[i] = 0;
            }
    for (i = 0; i < n; i++)
        if (use2[i])
        {
            ans[kol] = i + 1;
            kol++;
        }
    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%d\n", ans[i]);
    return 0;
}

void dfs(int v, int p)
{
    tin[v] = sum++;
    use[v] = 1;
    fup[v] = tin[v];
    int i;
    for (i = 0; i < a[v].size(); i++)
    {
        if ((use[a[v][i]]) && (a[v][i] != p) && (a[v][i] != v))
            fup[v] = min(fup[v], tin[a[v][i]]);
        else if (!use[a[v][i]])
        {
            child[v]++;
            dfs(a[v][i], v);
            fup[v] = min(fup[v], fup[a[v][i]]);
            if (fup[a[v][i]] >= tin[v])
                use2[v] = 1;
        }
    }
}
