#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E18;
ll sim[27], a[2003][2003], up[2003][2003], down[2003][2003], dp[3][2003][2003];
int main()
{
    freopen("submarine.in", "r", stdin);
    freopen("submarine.out", "w", stdout);
    ll h, w, k, i, j, ans = -INF, vt;
    char c;
    cin >> k;
    for (i = 0; i < k; i++)
        scanf("%I64d", &sim[i]);
    cin >> h >> w;
    for (i = 1; i <= h; i++)
    {
        scanf("\n");
        for (j = 1; j <= w; j++)
        {
            scanf("%c", &c);
            a[i][j] = sim[ll(c -'a')];
        }
    }

    for (i = 1; i <= h; i++)
        for (j = 1; j <= w; j++)
            up[i][j] = max(a[i][j], a[i][j] + up[i - 1][j]);
    for (i = h; i > 0; i--)
        for (j = w; j > 0; j--)
            down[i][j] = max(a[i][j], a[i][j] + down[i + 1][j]);

    for (i = 1; i <= h; i++)
        for (j = 1; j <= w; j++)
        {
            dp[0][i][j] = max(dp[0][i][j - 1] + a[i][j], a[i][j]);
            vt = up[i][j];
            dp[1][i][j] = max(dp[1][i][j - 1] + a[i][j], vt);
            dp[1][i][j] = max(dp[1][i][j], dp[0][i][j - 1] + vt);
            vt = up[i][j] + down[i][j] - a[i][j];
            if (j > 1)
                dp[2][i][j] = dp[1][i][j - 1] + vt;
            if (j > 2)
                dp[2][i][j] = max(dp[2][i][j], dp[2][i][j - 1] + a[i][j]);
            if (j > 1)
                ans = max(dp[2][i][j], ans);
        }
    cout << ans << endl;
    return 0;
}


/*

2
-10 1
6 11
aaaaaaaaaaa
aaabaaaaaaa
aaabaaaabaa
abbbbbbbbba
aaaaaaaabaa
aaaaaaaaaaa


3
-4 -3 4
5 5
bbabc
ccaac
accba
baccb
baaaa
*/
