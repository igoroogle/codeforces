#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100010], sm[100010];
char a[100010];
int main()
{
    ll n, i;
    scanf("%s", &a);
    n = strlen(a);
    dp[0] = 0;
    sm[0] = 1;
    dp[1] = 0;
    sm[1] = 1;
    if (a[0] == '9')
        dp[1] = 1;

    for (i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        sm[i] = sm[i - 1];
        if (a[i - 1] == '9')
            dp[i]++;
        if (ll(a[i - 1] - '0') + ll(a[i - 2] - '0') == 9)
        {
            if (dp[i - 2] + 1 > dp[i])
            {
                dp[i] = dp[i - 2] + 1;
                sm[i] = sm[i - 2];
            }
            else if (dp[i - 2] + 1 == dp[i])
                sm[i]++;
        }
    }
    cout << sm[n] << endl;
    return 0;
}
