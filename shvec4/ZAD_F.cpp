#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2000000000000000000;
const ll MOD = 1000000007;
vector<ll>  a[100010], b[100010];
ll use[100010], color[100010], sum = 0, val[100010], ver[100010], mn[100010], vl[100010], kol = 0;
void dfs1(ll v);
void dfs2(ll v, ll vl);
int main()
{
    ll n, m, i, x, y, sm = 0, pt = 1;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &val[i]);
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    for (i = 0; i < n; i++)
        if (!use[i])
            dfs1(i);

    for (i = 0; i < n; i++)
        use[i] = 0;

    for (i = n - 1; i >= 0; i--)
        if (!use[ver[i]])
            {
                sum++;
                dfs2(ver[i], sum - 1);
            }

    for (i = 0; i < sum; i++)
    {
        mn[i] = INF;
        vl[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (val[i] < mn[color[i]])
        {
            mn[color[i]] = val[i];
            vl[color[i]] = 1;
        }
        else if (val[i] == mn[color[i]])
            vl[color[i]]++;
    }
    for (i = 0; i < sum; i++)
    {
        sm += mn[i];
        pt = (pt * vl[i]) % MOD;
    }
    cout << sm << ' ' << pt << endl;
    return 0;
}

void dfs1(ll v)
{
    use[v] = 1;
    ll i;
    for (i = 0; i < a[v].size(); i++)
    if (!use[a[v][i]])
        dfs1(a[v][i]);
    kol++;
    ver[kol - 1] = v;
}

void dfs2(ll v, ll vl)
{
    use[v] = 1;
    color[v] = vl;
    ll i;
    for (i = 0; i < b[v].size(); i++)
    if (!use[b[v][i]])
        dfs2(b[v][i], vl);
}
