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
int sum[DL], a[DL], vl[DL];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, sm = 0, ttl = 0;
    fill(sum, sum + DL, -1);
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
    for (int j = 0; j < DL; ++j) {
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

    cout << ans << endl;
}
