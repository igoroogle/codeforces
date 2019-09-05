#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 203;
const ll MINDL = 100;
const ll INF = 2000000000000000010;
ll dp[DL][DL], x[DL], y[DL], a[DL], g[DL][DL];
int main()
{
    ll i, j, k, d, n;
    cin >> n >> d;
    for (i = 1; i < n - 1; i++)
        scanf("%I64d", &a[i]);

    for (i = 0; i < n; i++)
        scanf("%I64d%I64d", &x[i], &y[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d - a[i];
    for (i = 0; i < n; i++)
        g[i][i] = 0;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
    cout << g[0][n - 1] << endl;
    return 0;
}
