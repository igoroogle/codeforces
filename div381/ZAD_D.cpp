#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
const ll DL = 200010;
ll a[DL], dp[DL], ds[DL], pr[DL], w[DL], ps[20][DL], pv[20][DL];
int main() {
    ll n, i;
    cin >> n;
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }

    for (i = 1; i < n; ++i) {
        scanf("%I64d%I64d", &pr[i], &w[i]);
        --pr[i];
    }

    for (i = 0; i < n; ++i) {
        pv[0][i] = pr[i];
        ps[0][i] = w[i];
    }

    for (i = 1; i < 20; ++i) {
        for (j = 0; j < n; ++j) {
            if (pv[i - 1][j] == 0) {
                pv[i][j] = 0;
                ps[i][j] = ps[i - 1][j];
            } else {
                pv[i][j] = pv[i - 1][pv[i - 1][j]];
                ps[i][j] = ps[i - 1][j] + ps[i - 1][pv[i - 1][j]];
            }
        }
    }

    for (i = 0; i < n; ++i) {

    }
}
