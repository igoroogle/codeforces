#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, ll> a[1010];
ll sum[1010];
int main()
{
    freopen("conquest.in", "r", stdin);
    freopen("conquest.out", "w", stdout);
    ll n, i, val = 0, sm = 0;
    cin >> n;
    a[0].first = 0;
    a[0].second = 0;
    for (i = 1; i <= n; i++)
        scanf("%I64d%i64d", &a[i].first, &a[i].second);
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i].first;
    for (i = n; i > 0; i--)
    {
        while (a[i].first >= sum[i - 1] + val)
        {
            a[i].first--;
            val++;
            sm += a[i].second;
        }
    }
    for (i = 1; i <= n; i++)
    {
        while (a[i].first >= val)
        {
            a[i].first--;
            val++;
            sm += a[i].second;
        }
        val += a[i].first;
        a[i].first = 0;
    }
    cout << sm << endl;
    return 0;
}
