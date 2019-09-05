#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int DL = 200002;
const int INF = 2000000028;
int dp[DL];
int main()
{
    int i, j, n, m, ans = 0, val, sm = 0, vv;
    bool f;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        dp[i] = INF;
    dp[0] = 1;
    for (i = 1; ; i++)
    {
        sm += i;
        f = 1;
        val = 0;
        for (j = n; j >= 0; j--)
        {
            vv = INF;
            if ((dp[j] < INF) && (sm - j <= m))
                vv = dp[j];

            if ((j - i >= 0) && (dp[j - i] < INF))
                {
                    if (vv < INF)
                        vv = (vv + dp[j - i]) % MOD;
                    else
                        vv = dp[j - i];
                }

            if (vv < INF)
            {
                f = 0;
                val = (vv + val) % MOD;
            }

            dp[j] = vv;
        }
        if (f)
            break;
        ans = val;
    }
    cout << ans << endl;
    return 0;
}
