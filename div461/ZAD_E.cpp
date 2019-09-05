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
const ll INF = 1E18 + 3;
const ll DL = 10002;
ll dp[DL], c[1003], cost[1003];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, w, b, x;
    cin >> n >> w >> b >> x;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    for (int i = 1; i < DL; ++i) {
        dp[i] = -INF;
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            for (int j = 1; j < DL; ++j) {
                if (dp[j] != -INF) {
                    dp[j] = min(dp[j] + x, w + ll(j) * b);
                }
            }
        } else {
            dp[0] = w;
        }

        for (int j = 0; j < c[i]; ++j) {
            for (int k = DL - 1; k > 0; --k) {
                if (dp[k - 1] != -INF && dp[k - 1] >= cost[i]) {
                    dp[k] = max(dp[k], dp[k - 1] - cost[i]);
                }
            }
        }
    }

    for (int i = DL - 1; i >= 0; --i) {
        if (dp[i] != -INF) {
            cout << i << endl;
            return 0;
        }
    }
}
