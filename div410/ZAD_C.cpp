#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010], dp[100010][2];
const ll INF = 1E9;
ll gcd(ll a, ll b) {
    if ((a < 0) || (b < 0)) {
        return gcd(abs(a), abs(b));
    }

    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, i, ans = 0, x, y;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        ans = gcd(ans, a[i]);
    }

    cout << "YES\n";
    if (ans != 1) {
        cout << 0 << endl;
        return 0;
    }

    ans = 0;
    dp[0][0] = INF;
    dp[0][1] = INF;
    dp[0][abs(a[0]) % 2] = 0;
    for (i = 1; i < n; ++i) {
        dp[i][0] = INF;
        dp[i][1] = INF;
        if (a[i] % 2) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2);
        } else {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2);
        }
    }
    cout << dp[n - 1][0] << endl;
    return 0;
}
