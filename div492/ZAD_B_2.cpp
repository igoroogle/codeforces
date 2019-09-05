#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9;
int a[117], dp[103][103];

int main() {
    ios_base::sync_with_stdio(0);
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = -INF;
        }
    }

    for (int i = 1; i <= n; ++i){
        int ch = 0, nc = 0;
        for (int j = i; j > 0; --j) {
            if (a[j] % 2) {
                ++nc;
            } else {
                ++ch;
            }

            if (ch != nc) {
                continue;
            }

            for (int k = 0; k <= b; ++k) {
                int vl = 0;
                if (j > 1) {
                    vl = abs(a[j] - a[j - 1]);
                }

                if (vl <= k) {
                    int t = 0;
                    if (j > 1) {
                        t = 1;
                    }

                    if (dp[j - 1][k - vl] != -INF) {
                        dp[i][k] = max(dp[i][k], t + dp[j - 1][k - vl]);
                    }
                }
            }
        }
    }

    cout << dp[n][b] << endl;
}
