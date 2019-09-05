#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 2E18 + 3;
int dp[3][2003][2003], dp2[3][2003][2003], a[2010], b[2010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, i;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
    }


    for (int i = 1; i <= n; ++i)  {
        if (a[i] == 0) {
            dp[0][i][i] = 1;
            dp[1][i][i] = 1;
            dp[2][i][i] = 0;
        } else {
            dp[0][i][i] = 0;
            dp[1][i][i] = 1;
            dp[2][i][i] = 1;
        }

        for (int j = i + 1; j <= n; ++j) {
            dp[0][i][j] = dp[0][i][j - 1];
            dp[1][i][j] = dp[1][i][j - 1];
            dp[2][i][j] = dp[2][i][j - 1];
            if (a[j] == 0) {
                dp[0][i][j] = dp[0][i][j - 1] + 1;
                dp[1][i][j] = max(dp[1][i][j], dp[0][i][j]);
            } else {
                dp[1][i][j] = dp[1][i][j - 1] + 1;
                dp[2][i][j] = dp[2][i][j - 1] + 1;
            }
        }
    }

    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)  {
        if (a[i] == 0) {
            dp2[0][i][i] = 1;
            dp2[1][i][i] = 1;
            dp2[2][i][i] = 0;
        } else {
            dp2[0][i][i] = 0;
            dp2[1][i][i] = 1;
            dp2[2][i][i] = 1;
        }

        for (int j = i + 1; j <= n; ++j) {
            dp2[0][i][j] = dp2[0][i][j - 1];
            dp2[1][i][j] = dp2[1][i][j - 1];
            dp2[2][i][j] = dp2[2][i][j - 1];
            if (a[j] == 0) {
                dp2[0][i][j] = dp2[0][i][j - 1] + 1;
                dp2[1][i][j] = max(dp2[1][i][j], dp2[0][i][j]);
            } else {
                dp2[1][i][j] = dp2[1][i][j - 1] + 1;
                dp2[2][i][j] = dp2[2][i][j - 1] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans = max(ans, dp[0][1][i - 1] + dp2[0][n - j + 1][n - i + 1] + dp[1][j + 1][n]);
            ans = max(ans, dp[0][1][i - 1] + dp2[1][n - j + 1][n - i + 1] + dp[2][j + 1][n]);
            ans = max(ans, dp[1][1][i - 1] + dp2[2][n - j + 1][n - i + 1] + dp[2][j + 1][n]);
        }
    }
    cout << ans << endl;
}
