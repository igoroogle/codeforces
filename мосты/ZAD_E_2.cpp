#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 200010;
vector<int> a[DL];
int ans[DL], sum = 0, kol = 0;
bool use[DL], use2[DL];
void dfs(int v);
int main()
{
    //freopen("firesafe.in", "r", stdin);
    //freopen("firesafe.out", "w", stdout);
    int n, m, x, y, i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
    }

    for (i = 0; i < n; i++)
        if (!use[i])
            dfs(i);
    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%d ", ans[i]);
    return 0;
}

void dfs(int v)
{
    use[v] = 1;
    int i;
    for (i = 0; i < a[v].size(); i++)
    {
        if (!use[a[v][i]])
            dfs(a[v][i]);
        if (use2[a[v][i]])
            use2[v] = 1;
    }

    if (!use2[v])
    {
        use2[v] = 1;
        ans[kol] = v + 1;
        kol++;
    }
}
