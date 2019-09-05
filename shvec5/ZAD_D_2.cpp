#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 1003;
const ll INF = 1000000000000000000;
pair<ll,ll> a[DL];
ll val[DL][DL];
int main()
{
    ll n, m, sum = 0, mn, i, j, x, y, z;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            val[i][j] = INF;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    cin >> m;

    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d%I64d", &x, &y, &z);
        x--;
        y--;
        val[x][y] = min(z, val[x][y]);
    }

    for (i = 1; i < n; i++)
    {
        mn = INF;
        for (j = 0; j < i; j++)
            mn = min(mn, val[a[j].second][a[i].second]);
        if (mn == INF)
        {
            cout << -1 << endl;
            return 0;
        }
        sum += mn;
    }
    cout << sum << endl;
    return 0;
}
