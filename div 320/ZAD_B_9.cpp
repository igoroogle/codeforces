#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lef[200010], rig[200010], a[200010];
int main()
{
    ll ans = 0, i, j, k, n, x, t;
    cin >> n >> k >> x;
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (i = 1; i <= n; i++)
        lef[i] = lef[i - 1] | a[i];

    for (i = n; i > 0; i--)
        rig[i] = rig[i + 1] | a[i];
    t = 1;
    for (i = 0; i < k; i++)
        t *= x;
    for (i = 1; i <= n; i++)
        ans = max(ans, lef[i - 1] | rig[i + 1] | (a[i] * t));
    cout << ans << endl;
    return 0;
}
