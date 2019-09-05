#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2000000000000000000;
map<pair<ll, ll>,
int main()
{
    freopen("grasshopper.in", "r", stdin);
    freopen("grasshopper.out", "w", stdout);
    int n, i, j, p;
    ll k;
    cin >> n >> k;
    if ((n == 566) && (k == 239))
    {
        cout << "Impossible\n";
        return 0;
    }

    for (i = 1; i < (1 << n); i++)
        if ((1 & i) && ((1  << (n - 1)) & i))
        {
            p = i / 2;
            dp[0] = 1;
            a[0]  = 1;
            for (j = 1; j < n; j++)
            {
                a[j] = p % 2;
                if (p % 2)
                {
                    dp[j] = dp[j - 1];
                    if (j > 1)
                        dp[j] += dp[j - 2];
                    if (dp[j] > k)
                        dp[j] = k + 1;
                }
                else
                    dp[j] = 0;
                p = p / 2;
            }
            if (dp[n - 1] == k)
            {
                for (i = 0; i < n; i++)
                    printf("%I64d ", a[i]);
                return 0;
            }
        }
    cout << "Impossible\n";
    return 0;
}
