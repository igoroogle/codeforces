#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E18;
ll a[100010], d[100010];
int main()
{
    freopen("hotels.in", "r", stdin);
    freopen("hotels.out", "w", stdout);
    ll n, t, l, r, k, ans, mn, vmn, i, j, v1, v2;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d%I64d", &a[i], &d[i]);
    cin >> t;
    while (t--)
    {
        scanf("%I64d%I64d%I64d", &l, &r, &k);
        l--;
        r--;
        k--;
        ans = INF;
        for (i = l; i <= r; i++)
            ans = min(ans, a[i] + d[i] * k);
        printf("%I64d\n", ans);
    }

    return 0;
}


/*
2 1
Russia Russia go go go
Russia Russia lets go
*/
