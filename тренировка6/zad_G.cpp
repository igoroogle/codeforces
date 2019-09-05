#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
/*#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define sz(n) n.size()
#define x first
#define y second*/
vector <ll> a[100010];
ll dp[100010], kv[100010], ans1 = 0, ans2 = INF;
ll sum = 0;
void dfs(ll v, ll p);
int main()
{
    freopen("hospital.in", "r", stdin);
    freopen("hospital.out", "w", stdout);
    ll n, i, x, y;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            scanf("%I64d", &kv[i]);
            sum += kv[i];
        }
    for (i = 0; i < n - 1; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(0, -1);
    cout << ans1 + 1 << endl;
    return 0;
}

void dfs(ll v, ll p)
{
    ll i, mx = 0, sm = 0;
    for (i = 0; i < a[v].size(); i++)
    if (a[v][i] != p)
    {
        dfs(a[v][i], v);
        sm += dp[a[v][i]];
        mx = max(dp[a[v][i]], mx);
    }
    dp[v] = sm + kv[v];
    mx = max(sum - dp[v], mx);
    if (mx < ans2)
    {
        ans1 = v;
        ans2 = mx;
    }
}
