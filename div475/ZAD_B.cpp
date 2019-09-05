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
const ll INF = 1E18;
ll dp[1003][1003], tim[1003];

int main() {
    ios_base::sync_with_stdio(0);
    ll n, a, b, c, t, x;
    cin >> n >> a >> b >> c >> t;

    for (ll i = 0; i < n; ++i) {
        cin >> x;
        ++tim[x];
    }

    for (ll i = 1; i <= t; ++i) {
        dp[0][i] = -INF;
    }

    for (ll i = 1; i <= t; ++i) {
        for (ll j = 0; j <= t; ++j) {
            dp[i][j] = -INF;
        }
        for (ll j = 0; j <= t; ++j) {
            if (dp[i - 1][j] == -INF) {
                continue;
            }
            dp[i][j + tim[i]] = max(dp[i][j + tim[i]], dp[i - 1][j] + a * tim[i] + (c - b) * j)
        }
    }
}
