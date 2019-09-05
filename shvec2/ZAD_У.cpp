#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
int d[DL], dp[DL];
int main()
{
    int n, i, j, x, mx = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        for (j = 1; j * j <= x; j++)
            if (!(x % j))
            {
                dp[i] = max(dp[i], dp[d[x / j]] + 1);
                if (j > 1)
                    dp[i] = max(dp[i], dp[d[j]] + 1);
                d[j] = i;
                d[x / j] = i;
            }
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
    return 0;
}
