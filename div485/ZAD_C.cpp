#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;

ll a[3010], c[3010], dp[3010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        dp[i] = INF;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) {
                dp[i] = min(dp[i], c[i] + c[j]);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((dp[j] == INF) || (a[j] <= a[i])) {
                continue;
            }

            ans = min(ans, c[i] + dp[j]);
        }
    }


    if (ans == INF) {
        ans = -1;
    }

    cout << ans << '\n';
}
