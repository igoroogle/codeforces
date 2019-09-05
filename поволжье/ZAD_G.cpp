#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
int a[1002], dp[1002][1002];
string s = "";
int main()
{
    int i, j, n, k, p = 0, t = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dp[0][0] = 3;
    for (i = 1; i <= n; i++)
        for (j = 0; j <= k; j++)
        {
            if ((j - a[i] >= 0) && (dp[i - 1][j - a[i]] > 0))
                dp[i][j] = 1;
            else if ((j + a[i] <= k) && (dp[i - 1][j + a[i]] > 0))
                dp[i][j] = 2;
            else
                dp[i][j] = 0;
            if (dp[i][j] > 0)
            {
                p = i;
                t = j;
            }
        }
    cout << p << endl;
    for (i = p; i > 0; i--)
    {
        if (dp[i][t] == 1)
        {
            s = '+' + s;
            t = t - a[i];
        }
        else
        {
            s = '-' + s;
            t = t + a[i];
        }
    }
    cout << s << endl;
    return 0;
}
