#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][100010];
vector <ll> a[100010], b[100010];
void dfs(ll v, ll past);
int main()
{
    ll n, i, x, y, w;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        scanf ("%I64d%I64d%I64d", &x, &y, &w);
        x--;
        y--;
        a[x].push_back(y);
        b[x].push_back(w);
        a[y].push_back(x);
        b[y].push_back(w);
    }

    dfs(0, -1);
    cout << dp[0][0] << endl;
    return 0;
}
void dfs(ll v, ll past)
{
    ll i, sm = 0;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != past)
        {
            dfs(a[v][i], v);
            sm += b[v][i] * 2 + dp[1][a[v][i]];
        }
    dp[1][v] = sm;
    dp[0][v] = sm;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != past)
            dp[0][v] = min(dp[0][v], sm - b[v][i] - dp[1][a[v][i]] + dp[0][a[v][i]]);
}
