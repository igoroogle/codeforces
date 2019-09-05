#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 203;
const ll MINDL = 100;
const ll INF = 2000000000000000010;
ll dp[2][2001], a[2001], n, k;
bool prov(ll val);
int main()
{
    ll i, j, l = 0, r = 4000000000, m;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    while (l < r)
    {
        m = (l + r) / 2;
        if (prov(m)) l = m + 1;
        else r = m;
    }
    cout << l << endl;
    return 0;
}
bool prov(ll val)
{
    ll i, j;
    dp[0][0] = 0;
    dp[1][0] = 1;
    for (i = 1; i < n; i++)
    {
        dp[0][i] = i;
        dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
        for (j = i - 1; j >= 0; j--)
            if (abs(a[i] - a[j]) <= (i - j) * val)
                dp[0][i] = min(dp[0][i], i - j - 1 + dp[0][j]);
    }
    return min(dp[0][n - 1], dp[1][n - 1]) > k;
}
