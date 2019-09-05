#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll dp[2][100010];
int main()
{
    ll n, i;
    cin >> n;
    dp[0][0] = 20;
    dp[1][0] = 7;
    for (i = 1; i < n; i++)
    {
        dp[0][i] = (dp[0][i] + 7 * dp[0][i - 1]) % MOD;
        dp[0][i] = (dp[0][i] + 20 * dp[0][i - 1]) % MOD;
        dp[0][i] = (dp[0][i] + 20 * dp[1][i - 1]) % MOD;
        dp[1][i] = (7 * dp[1][i - 1]) % MOD;
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
