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
const int DL = 10002;
const int VL = 102;
bool dp[VL][DL];
int a[DL], vl[DL];

int main() {
    ios_base::sync_with_stdio(0);
    int n, sm = 0, ttl = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
        ++vl[a[i]];
        if (vl[a[i]] == 1) {
            ++ttl;
        }
    }

    if (ttl <= 2) {
        cout << n << endl;
        return 0;
    }

    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = DL - a[i] - 1; j >= 0; --j) {
            for (int k = 0; k <= i; ++k) {
                if (dp[k][j]) {
                    dp[k + 1][j + a[i]] = true;
                }
            }
        }
    }

    int ans = 1;
    for (int j = 1; j < DL; ++j) {
        for (int k = 0; k < n; ++k) {
            if (j % a[k] != 0) {
                continue;
            }

            if (j / a[k] > vl[a[k]]) {
                continue;
            }

            bool f = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] == a[k]) {
                    continue;
                }

                if (j - a[i] < 0) {
                    continue;
                }

                if (dp[j / a[k] - 1][j - a[i]]) {
                    f = false;
                    break;
                }
            }

            if (f) {
                ans = max(ans, j / a[k]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int vans = -1;
        bool f = true;
        while(f) {
            ++vans;
            if (n - vans == 0) {
                break;
            }

            if ((sm - a[i] * (vans + 1) < 0) || (!dp[n - vans - 1][sm - (a[i] * (vans + 1))])) {
                break;
            }

            for (int j = 0; j < n; ++j) {
                if (a[j] == a[i]) {
                    continue;
                }

                if (sm - a[i] * vans - a[j] < 0) {
                    continue;
                }

                if (dp[n - vans - 1][sm - a[i] * vans - a[j]]) {
                    f = false;
                    break;
                }
            }
        }

        ans = max(ans, vans);
    }

    cout << ans << endl;
}
