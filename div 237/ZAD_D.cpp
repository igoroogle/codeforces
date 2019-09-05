#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n;
string s;
int dp[5][1000010];
int main()
{
    int i, n, ans;
    cin >> s;
    n = s.length();
    if ((s[0] == '0') || (s[0] == '?')) dp[0][0]++;
    if ((s[0] == '1') || (s[0] == '?')) dp[1][0]++;
    if ((s[0] == '*') || (s[0] == '?')) dp[4][0]++;
    for (i = 1; i < n; i++)
    {
        if ((s[i] == '0') || (s[i] == '?'))
        {
            dp[0][i] = (dp[0][i] + dp[0][i - 1]) % MOD;
            dp[0][i] = (dp[0][i] + dp[2][i - 1]) % MOD;
        }

        if ((s[i] == '1') || (s[i] == '?'))
        {
            dp[1][i] = (dp[1][i] + dp[0][i - 1]) % MOD;
            dp[1][i] = (dp[1][i] + dp[2][i - 1]) % MOD;
            dp[2][i] = (dp[2][i] + dp[4][i - 1]) % MOD;
        }

        if ((s[i] == '2') || (s[i] == '?'))
            dp[3][i] = (dp[3][i] + dp[4][i - 1]) % MOD;

        if ((s[i] == '*') || (s[i] == '?'))
        {
            dp[4][i] = (dp[4][i] + dp[4][i - 1]) % MOD;
            dp[4][i] = (dp[4][i] + dp[1][i - 1]) % MOD;
            dp[4][i] = (dp[4][i] + dp[3][i - 1]) % MOD;
        }
    }
    ans = (dp[0][n - 1] + dp[2][n - 1]) % MOD;
    ans = (ans + dp[4][n - 1]) % MOD;
    cout << ans << endl;
    return 0;
}
