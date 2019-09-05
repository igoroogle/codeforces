#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 200010;
vector<int> a[DL];
int r1[DL], r2[DL], tin[DL], fup[DL], ans[DL], sum = 0;
bool use[DL];
map < pair<int, int>, int> t;
void dfs(int v, int p);
int main()
{
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
    int n, m, x, y, kol = 0, i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
        r1[i] = x;
        r2[i] = y;
    }
    for (i = 0; i < n; i++)
        if (!use[i])
            dfs(i, -1);
    for (i = 0; i < m; i++)
        if (t[make_pair(r1[i], r2[i])] == 1)
        {
            ans[kol] = i + 1;
            kol++;
        }
    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%d ", ans[i]);
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
            dfs(a[v][i], v);
            fup[v] = min(fup[v], fup[a[v][i]]);
            if (fup[a[v][i]] > tin[v])
            {
                t[make_pair(v, a[v][i])]++;
                t[make_pair(a[v][i], v)]++;
            }
        }
    }
}
