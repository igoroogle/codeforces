#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)

using namespace std;
typedef unsigned long long ll;
typedef long double ld;
const ll LEN = 32;
ll dp[LEN], vt[LEN];

int main() {

    dp[1] = 1;
    for (int i = 2; i < LEN; ++i) {
        dp[i] = dp[i - 1] * ll(4) + ll(1);
    }

    int t;
    cin >> t;
    while (t--) {
        ll n, k, kv = 1, ans = 0;
        cin >> n >> k;
        ll vn = n;

        while ((vn > ll(0)) && (dp[n - vn + 1] <= k)) {
            --vn;
        }

        if (dp[n - vn] == k) {
            cout << "YES " << vn << '\n';
            continue;
        } else if (vn == ll(0)) {
            cout << "NO\n";
            continue;
        } else if (dp[n - vn + 1] - ((ll(1) << (n - vn + 1)) - ll(1)) >= k) {
            cout << "YES " << vn << '\n';
            continue;
        }

        if (((ll(1) << (n - vn + 1)) - ll(1)) + dp[n - vn] <= k) {
            cout << "YES " << vn - 1 << '\n';
            continue;
        }

        ll zn = dp[n - vn + 1] - ((ll(1) << (n - vn + 1)) - ll(1));
        ll indVn = vn - 1;
        while ((indVn > 0) && (zn < k)) {
            zn = zn * ll(4) + ll(1);
            --indVn;
        }

        if (zn > k) {
            cout << "YES " << vn << '\n';
        }
        else {
            cout << "NO\n";
        }

    }
}
