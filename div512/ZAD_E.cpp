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
ll dp[300003][2];
vector<ll> a;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll x, dl = 0;
        cin >> x;
        while (x > 0) {
            dl += (x & ll(1));
            x >>= ll(1);
        }

        if (dl % ll(2)) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + ll(1);
        } else {
            dp[i][0] = dp[i - 1][0] + ll(1);
            dp[i][1] = dp[i - 1][1];
        }
        ans += dp[i][0];
        a.pb(dl);
    }

    for (int i = 0; i < n; ++i) {
        ll sm = 0, mx = 0;
        for (int j = i; j < min(n, i + 65); ++j) {
            sm += a[j];
            mx = max(mx, a[j]);
            if ((sm - mx < mx) && (sm % ll(2) == 0)) {
                --ans;
            }
        }
    }

    cout << ans << '\n';
}
