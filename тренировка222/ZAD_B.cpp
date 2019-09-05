#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
/*
#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define x first
#define y second

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll MOD = 1000000007;
const int INF = 2e9;
const int N = 200001;
*/
const ll DL = 100010;
const ll INF = 2E18;
vector<ll> a[DL], b[DL];
ll sum[DL], kol[DL], sum2[DL], answ[DL], cnt = 0, mn = INF;
ll ans(ll ras, ll sum, ll kol, ll sum2);
void dfs1(ll v, ll p);
void dfs2(ll v, ll p, ll sum0, ll kol0, ll sum20);
int main()
{
    freopen("bfs.in", "r", stdin);
    freopen("bfs.out", "w", stdout);
    ll n, x, y, z, i;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%I64d%I64d%I64d", &x, &y, &z);
        x--;
        y--;
        a[x].push_back(y);
        b[x].push_back(z);
        a[y].push_back(x);
        b[y].push_back(z);
    }
    dfs1(0, - 1);
    dfs2(0, - 1, 0, 0, 0);
    cout << cnt << endl;
    for (i = 0; i < cnt; i++)
        printf("%I64d\n", answ[i]);
    return 0;
}

ll ans(ll ras, ll sum, ll kol, ll sum2)
{
    return ras * ras * kol + sum2 + 2 * ras * sum;
}

void dfs1(ll v, ll p)
{
    ll i;
    sum[v] = 0;
    kol[v] = 0;
    sum2[v] = 0;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != p)
        {
            dfs1(a[v][i], v);
            kol[v] += kol[a[v][i]];
            sum[v] += sum[a[v][i]] + b[v][i] * kol[a[v][i]];
            sum2[v] += ans(b[v][i], sum[a[v][i]], kol[a[v][i]], sum2[a[v][i]]);
        }
    kol[v]++;
    //cout << sum2[v] << ' ' << v + 1 << endl;
}

void dfs2(ll v, ll p, ll sum0, ll kol0, ll sum20)
{
    ll i, sum1, kol1, sum21, sumt, sum2t, kolt;
    //cout << sum20 << ' ' << ' ' << sum0 << ' ' << kol0 << ' ' << v + 1 << endl;
    if (sum20 + sum2[v] < mn)
    {
        mn = sum20 + sum2[v];
        cnt = 1;
        answ[0] = v + 1;
    }
    else if (sum20 + sum2[v] == mn)
            answ[cnt++] = v + 1;

    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != p)
        {
            kol1 = kol0 + kol[v] - kol[a[v][i]];
            sum1 = sum0 + sum[v] - sum[a[v][i]] - b[v][i] * kol[a[v][i]] + b[v][i] * kol1;
            //cout << sum1 << ' ' << "jkhjk" << ' ' << sum[v] - sum[a[v][i]] - b[v][i] * kol[a[v][i]] << ' ' << sum0 << ' '  << b[v][i] * kol1 << ' ' << kol1 << ' ' << b[v][i] << endl;
            sum2t = sum20 + sum2[v] - ans(b[v][i], sum[a[v][i]], kol[a[v][i]], sum2[a[v][i]]);
            sumt = sum0 + sum[v] - sum[a[v][i]] - b[v][i] * kol[a[v][i]];
            kolt = kol0 + kol[v] - kol[a[v][i]];
            sum21 = ans(b[v][i], sumt, kolt, sum2t);
            dfs2(a[v][i], v, sum1, kol1, sum21);
        }
}
/*
6
6 3 35
5 2 12
4 5 31
4 6 14
3 1 40
*/
