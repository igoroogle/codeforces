#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
vector<int> a[50000];
int dp[501][50000], n, k;
ll ans;
void dfs1(int v, int p);
void dfs2(int v, int p);
int main()
{
    int i, j, x, y;
    cin >> n >> k;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].pb(y);
        a[y].pb(x);
    }

    dfs1(0, -1);
    dfs2(0, -1);
    cout << ans / 2 << endl;
    return 0;
}

void dfs1(int v, int p)
{
    int i, j;
    dp[0][v] = 1;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != p)
        {
            dfs1(a[v][i], v);
            for (j = 1; j <= k; j++)
                dp[j][v] += dp[j - 1][a[v][i]];
        }
}

void dfs2(int v, int p)
{
    int i, vl;
    ans += ll(dp[k][v]);
    if (p != -1)
    {
        for (i = 1; i <= k; i++)
        {
            vl = dp[k - i][p];
            if (k - i - 1 >= 0)
                vl -= dp[k - i - 1][v];
            ans += ll(vl) * ll(dp[i - 1][v]);
        }
    }
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != p)
            dfs2(a[v][i], v);
}
