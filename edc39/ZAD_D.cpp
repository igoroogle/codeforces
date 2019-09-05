#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9;
int a[510], val[510][510], dp[510][510];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            val[i][j] = INF;
            dp[i][j] = INF;
        }
        cin >> s;
        a[0] = 0;
        for (int j = 0; j < m; ++j) {
            a[j + 1] = a[j] + int(s[j] - '0');
        }

        for (int j = 0; j <= k; ++j) {
            if (a[m] <= j) {
                val[i][j] = 0;
            }
        }

        for (int j = 1; j <= m; ++j) {
            for (int p = j; p <= m; ++p) {
                if (a[p] - a[j - 1] + k >= a[m]) {
                    val[i][a[m] - a[p] + a[j - 1]] = min(p - j + 1, val[i][a[m] - a[p] + a[j - 1]]);
                }
            }
        }

        for (int j = 1; j <= k; ++j) {
            val[i][j] = min(val[i][j], val[i][j - 1]);
        }

        for (int j = 0; j <= k; ++j) {
            if (j > 0) {
                dp[i][j] = min(dp[i][j - 1], dp[i][j]);
            }
            for (int p = 0; p <= j; ++p) {
                if (dp[i - 1][j] == INF) {
                    continue;
                }
                dp[i][j] = min(dp[i - 1][p] + val[i][j - p], dp[i][j]);
            }
        }
    }


    cout << dp[n][k] << endl;
}
