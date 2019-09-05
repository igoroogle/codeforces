#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int LEN = 1000;
const ll INF = 10000000000000000;
ll n, k, ar[LEN], dp[LEN][LEN * 3], use[LEN][LEN * 3];

void rec(ll n, ll k);

int main()
{
    freopen("sandwiches.in", "r", stdin);
    freopen("sandwiches.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    if (k > 2 * n)
    {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    use[0][0] = 1;

    rec(n, k);

    if (dp[n][k] > 0)
        cout << dp[n][k];
    else
        cout << "Impossible";

    return 0;
}

void rec(ll n, ll k)
{
    use[n][k] = 1;

    if (k > 2 * n)
        return;

    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            if (!use[n - i][k - i])
                rec(n - i, k - i);
            dp[n][k] = max(dp[n][k], dp[n - i][k - i] + ar[i]);
        }
        if (i <= k - 1)
        {
            if (!use[n - i][k - i - 1])
                rec(n - i, k - i - 1);
            dp[n][k] = max(dp[n][k], dp[n - i][k - i - 1] + ar[i]);
        }
    }
}
