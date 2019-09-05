#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 5003;
const ll MOD = 1000000007;
string s;
bool val[DL][DL];
ll sum[DL][DL], dp[DL][DL];
int main()
{
    ll n, i, j, k, ans;
    bool f;
    cin >> s;
    n = s.length();
    for (j = 1; j <= n; j++)
    {
        for (i = j + j - 1; i < n; i++)
        {
            f = 0;
            for (k = i - j + 1; k <= i; k++)
            if (s[k] != s[k - j])
            {
                if (s[k] < s[k - j])
                    break;
                f = 1;
                break;
            }
            val[i][j] = f;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= i; j++)
            if (s[i - j + 1] != '0')
            {
                dp[i][j] = sum[i - j][j - 1];
                if (val[i][j])
                    dp[i][j] = (dp[i][j] + dp[i - j][j]) % MOD;
            }

        dp[i][i + 1] = 1;

        sum[i][0] = dp[i][0];
        for (j = 1; j <= n; j++)
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
    }

    ans = 0;
    for (i = 0; i <= n; i++)
        ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;
    return 0;
}
