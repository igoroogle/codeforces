#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 103;
const int MOD = 1000000007;
const int INF = 20000000010;
int dp[2][DL], n, k, d;
int rec(int type, int v);
int main()
{
    int i;
    cin >> n >> k >> d;
    for (i = 0; i <= n; i++)
    {
        dp[0][i] = INF;
        dp[1][i] = INF;
    }
    cout << rec(1, n);
    return 0;
}
int rec(int type, int v)
{
    if (dp[type][v] != INF)
        return dp[type][v];
    dp[type][v] = 0;
    int i;
    for (i = 1; i <= k; i++)
        if (v - i >= 0)
        {
            if (v - i > 0)
            {
                if (i >= d)
                    dp[type][v] = (dp[type][v] + rec(0, v - i)) % MOD;
                else
                    dp[type][v] = (dp[type][v] + rec(type, v - i)) % MOD;
            }
            else if ((i >= d) || (type == 0))
                dp[type][v] = (dp[type][v] + 1) % MOD;
        }
    return dp[type][v];
}
