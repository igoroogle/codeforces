#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 2000000010;
int a[3][103], b[103], sum[3][103];
int main()
{
    int n, i, j, ans = INF, ss = 0;
    cin >> n;
    for (i = 0; i < 2; i++)
        for (j = 0; j < n - 1; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < 2; i++)
    {
        sum[i][0] = 0;
        for (j = 1; j < n; j++)
            sum[i][j] = sum[i][j - 1] + a[i][j - 1];
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        if (i != j)
        {
            ss = 0;
            ss = ss + sum[1][n - 1] - sum[1][i];
            ss = ss + b[i];
            ss = ss + sum[0][i];
            ss = ss + sum[0][j];
            ss = ss + b[j];
            ss = ss + sum[1][n - 1] - sum[1][j];
            ans = min(ans, ss);
        }
    cout << ans << endl;
    return 0;
}
