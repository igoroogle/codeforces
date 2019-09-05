#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll INF = 1E18;
vector <ll> a[100010];
pair < pair<ll, ll>, ll> r[100010];
bool use[100010];
ll num[100010], d[100010], n, ans = 0, sum, sans, cnt;
void get_ans(ll v);
void dtree(ll v, ll p);
void get_centre(ll v, ll p, ll val);
void dfs(ll v, ll p, ll sm, ll typ);
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ll i, x, y;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &num[i]);

    for (i = 0; i < n - 1; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        x--;
        y--;
        a[x].pb(y);
        a[y].pb(x);
    }

    get_ans(0);
    cout << ans << endl;
    return 0;
}

void get_ans(ll v)
{
    ll i;
    dtree(v, -1);
    sum = INF;
    sans = v;
    get_centre(v, -1, 0);
    cnt = 0;
    ll u = sans;
    for (i = 0; i < a[u].size(); i++)
        if (!use[a[u][i]])
            dfs(a[u][i], u, ll(1), i);
    sort(r, r + cnt);
    ll typ1 = -1, typ2 = -1, r1 = 0, r2 = 0;
    for (i = cnt - 1; i >= 0; i--)
    {
        ans = max(min(num[u], r[i].x.x) * r[i].x.y, ans);
        if ((typ1 != -1) && (typ1 != r[i].y))
            ans = max((r1 + r[i].x.y) * r[i].x.x, ans);

        if ((typ2 != -1) && (typ2 != r[i].y))
            ans = max((r2 + r[i].x.y) * r[i].x.x, ans);
        if ((typ1 == -1) || (r[i].x.y > r1))
        {
            if (typ1 == r[i].y)
                r1 = r[i].x.y;
            else
            {
                typ2 = typ1;
                r2 = r1;
                typ1 = r[i].y;
                r1 = r[i].x.y;
            }
        }

        if ((typ1 != r[i].y) && (r[i].x.y > r2))
        {
            typ2 = r[i].y;
            r2 = r[i].x.y;
        }
    }

    use[u] = 1;
    for (i = 0; i < a[u].size(); i++)
        if (!use[a[u][i]])
            get_ans(a[u][i]);
}

void dtree(ll v, ll p)
{
    d[v] = 1;
    for (ll i = 0; i < a[v].size(); i++)
        if ((!use[a[v][i]]) && (a[v][i] != p))
        {
            dtree(a[v][i], v);
            d[v] += d[a[v][i]];
        }
}

void get_centre(ll v, ll p, ll val)
{
    ll sm = val, mx = val, i;
    for (i = 0; i < a[v].size(); i++)
    if ((!use[a[v][i]]) && (a[v][i] != p))
        {
            mx = max(d[a[v][i]], mx);
            sm += d[a[v][i]];
        }
    sm++;

    if (mx < sum)
    {
        sum = mx;
        sans = v;
    }

    for (i = 0; i < a[v].size(); i++)
    if ((!use[a[v][i]]) && (a[v][i] != p))
        get_centre(a[v][i], v, sm - d[a[v][i]]);
}

void dfs(ll v, ll p, ll sm, ll typ)
{
    r[cnt++] = mp(mp(num[v], sm), typ);
    for (ll i = 0; i < a[v].size(); i++)
    if ((!use[a[v][i]]) && (a[v][i] != p))
        dfs(a[v][i], v, sm + 1, typ);
}
