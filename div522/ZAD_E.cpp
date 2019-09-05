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
const int DL = 10001;
const int VL = 101;
ll dp[VL][DL], pr[VL][DL];
int a[VL], vl[VL];
int main() {
    ios_base::sync_with_stdio(0);
    int n, k, sm = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
        ++vl[a[i]];
    }

    for (int i = 0; i < VL; ++i) {
        if (vl[i] > 0) {
            dp[i][1] = 1;
            dp[i][1] = i;
        }
    }


    for (int i = 2; i < VL; ++i) {
        for (int j = 1; j < VL; ++j) {
            if (vl[j] == 0) {
                continue;
            }

            for (int k = j + 1; k < DL; ++k) {
                if (dp[i][k] > 1) {
                    continue;
                }

                if (dp[i - 1][k - j] == 0) {
                    continue;
                }

                if (dp[i - 1][k - j] == 2) {
                    dp[i][k] = 2;
                    continue;
                }

                if (pr[i - 1][k - j] == )
            }
        }
    }
}
