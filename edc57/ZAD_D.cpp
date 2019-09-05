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
const ll MOD = 998244353;
const ll INF = 1E18 + 3;
ll dp[5][100003], a[100003];
const string val = "hard";

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = INF;
        }
    }

    if (s[0] == 'h') {
        dp[0][0] = a[0];
        dp[1][0] = 0;
    } else {
        dp[0][0] = 0;
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (dp[i][j - 1] == INF) {
                continue;
            }

            if (s[j] != val[i]) {
                dp[i][j] = min(dp[i][j - 1], dp[i][j]);
            } else {
                dp[i + 1][j] = min(dp[i][j - 1], dp[i + 1][j]);
                dp[i][j] = min(dp[i][j - 1] + a[j], dp[i][j]);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < 4; ++i) {
        ans = min(dp[i][n - 1], ans);
    }

    cout << ans << '\n';
}
