#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> a[100010];
ll dp[100010];
ll dfs(ll v);
int main()
{
    ll n, m, i, j, x, y, val, ans = 0;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        x--;
        y--;
        a[x].pb(y);
        a[y].pb(x);
    }

    for (i = 0; i < n; i++)
        dp[i] = -1;

    for (i = n - 1; i >= 0; i--)
    {
        val = dfs(i);
        ans = max(val * ll(a[i].size()), ans);
    }

    cout << ans << endl;
    return 0;
}

ll dfs(ll v)
{
    if (dp[v] != -1)
        return dp[v];
    ll i, mx = 1;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] < v)
            mx = max(mx, dfs(a[v][i]) + ll(1));
    dp[v] = mx;
    return mx;
}
