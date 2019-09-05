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
string s, ss;
bool val[DL][DL];
ll sum[DL][DL], dp[DL][DL], z[DL];
int main()
{
    ll n, m, i, j, k, ans, l, r;
    bool f;
    cin >> n >> s;
    for (k = 0; k < n; k++)
    {
        ss = s.substr(k, n - k);
        m = ss.length();
        z[0] = m;
        l = 0;
        r = 0;

        for (i = 1; i < m; i++)
        {
            if (i <= r)
                z[i] = min(z[i - l], r - i + 1);
            while ((i + z[i] < m) && (ss[i + z[i]] == ss[z[i]]))
                z[i]++;
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }

        i = k;
        for (j = i; j < n; j++)
            if ((z[j - i] < j - i) && (j + j - i <= n))
                val[j + j - i - 1][j - i] = (s[i + z[j - i]] < s[j + z[j - i]]);
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
