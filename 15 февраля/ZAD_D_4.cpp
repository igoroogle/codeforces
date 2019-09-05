#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E18;
ll a[100010], d[100010], a1[100010];
int main()
{
    //freopen("hotels.in", "r", stdin);
    //freopen("hotels.out", "w", stdout);
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
        ans = 0;

        for (i = 0; i < n; i++)
            a1[i] = a[i];

        for (i = 0; i < k; i++)
        {
            mn = l;
            for (j = l + 1; j <= r; j++)
                if (a1[j] < a1[mn])
                    mn = j;
            ans = max(a1[mn], ans);
            for (j = l; j <= r; j++)
                a1[j] += d[j];
        }
        printf("%I64d\n", ans);
    }

    return 0;
}


/*
2 1
Russia Russia go go go
Russia Russia lets go
*/
