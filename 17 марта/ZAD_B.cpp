#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300010];
int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    ll n, i, ans = 0, x, s = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d", &x);
        s -= a[i];
        ans += s * x;
        a[i + x]++;
        if (x > 0)
            s++;
    }
    cout << ans << endl;
    return 0;
}
