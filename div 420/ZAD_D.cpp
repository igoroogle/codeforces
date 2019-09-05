#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 2E18;
const ll DL = 10010;
ll n, m, k, x[DL], y[DL], d[3][DL];
bool use[2][DL];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, k, i, j, indx, indy, ans = INF;
    cin >> n >> m >> k;
    for (i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
        d[0][i] = INF;
        d[1][i] = INF;
        d[2][i] = INF;
        if ((x[i] == 0) && (y[i] == 0)) {
            d[0][i] = 0;
        }
    }

    for(;;) {
        indx = -1;
        for (i = 0; i < k; ++i) {
            for (j = 0; j < 3; ++j) {
                if ((!use[j][i]) && (d[j][i] < INF) && ((indx == -1) || (d[indx][indy] > d[j][i]))) {
                    indx = j;
                    indy = i;
                }
            }
        }

        if (indx == -1) {
            break;
        }

        use[indx][indy] = true;
        for (i = 0; i < k; ++i) {
            for (j = 0; j < 3; ++j) {
                if (use[j][i]) {
                    continue;
                }

                if ((abs(x[i] - x[indy] < 2)) || (abs(y[i] - y[indy] < 2))) {
                    d[j][i] = min(d[j][i], d[indx][indy] + ll(1));
                }


                if ((x[i] == x[indy]) && (y[i] == y[indy])) {
                    continue;
                }

                if ((j == 0) && (indx == 0)) {
                    if (abs(x[i] - x[indy]) + abs(y[i] - y[indy]) < 2) {
                        d[j][i] = min(d[j][i], d[indx][indy]);
                    }
                    continue;
                }

                if (indx == 0) {
                    continue;
                }

                if (indx == 1) {
                    if ((j == 1) || (j == 0)) {
                        if (((abs(y[i] - y[indy]) < 2) && (j == 0))
                            || ((y[i] == y[indy]) && (j == 1))) {
                            d[j][i] = min(d[j][i], d[indx][indy]);
                        }
                    }
                    continue;
                }

                if ((j == 2) || (j == 0)) {
                    if (((abs(x[i] - x[indy]) < 2) && (j == 0))
                            || ((x[i] == x[indy]) && (j == 1))) {
                            d[j][i] = min(d[j][i], d[indx][indy]);
                        }
                }
            }
        }
    }

    for (i = 0; i < k; ++i) {
        for (j = 0; j < 3; ++j) {
            if ((n - x[i] + m - y[i] == 2)) {
                ans = min(ans, d[j][i]);
                continue;
            }

            /*if ((m - y[i] == 1)  && (j == 1)) {
                ans = min(ans, d[j][i]);
                continue;
            }

            if ((j == 2) && (n - x[i] == 1)) {
                ans = min(ans, d[j][i]);
                continue;
            }

            if ((n - x[i] < 3) || (m - y[i] < 3)) {
                ans = min(ans, d[j][i] + ll(1));
                continue;
            }*/
        }
    }

    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}
