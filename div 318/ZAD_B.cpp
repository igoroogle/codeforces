#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int lef[100010], rig[100010], dp[100010], a[100010];
int main()
{
    int n, i, mn = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    lef[0] = 1;
    rig[n - 1] = 1;
    for (i = 1; i < n; i++)
        lef[i] = min(lef[i - 1] + 1, a[i]);
    for (i = n - 2; i >= 0; i--)
        rig[i] = min(rig[i + 1] + 1, a[i]);
    for (i = 0; i < n; i++)
        dp[i] = min(lef[i], rig[i]);
    for (i = 0; i < n; i++)
        mn = max(dp[i], mn);
    cout << mn << endl;
    return 0;
}
