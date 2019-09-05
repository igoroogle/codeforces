#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ull INF = 1E18 + ull(1);
const ull MINF = 1E9 + ull(4);
ull st[66], dp[66][66], n;
string s;
int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> s;
    ull i, j, k, tn = 0, ss;
    st[0] = 1;
    for (i = 1; i < 65; ++i) {
        st[i] = st[i - 1] * n;
        if (ull(sqrt(ld(st[i - 1]))) * ull(sqrt(ld(n))) > MINF) {
            st[i] = INF;
        }

        st[i] = min(INF, st[i]);
    }

    for (i = 0; i < s.length(); ++i) {
        for (j = 0; j < 65; ++j) {
            dp[i][j] = INF;
        }
    }

    for (i = 0; i <= s.length(); ++i) {
        tn = tn * ull(10) + ull(s[i] - '0');
        if (tn >= INF)
            break;

        for (j = 0; j < 65; ++j) {
            if (st[j] >= INF) {
                break;
            }

            if (ull(sqrt(ld(tn))) * ull(sqrt(ld(st[j]))) > MINF) {
                break;
            }

            if (tn >= n) {
                break;
            }

            dp[i][j] = min(dp[i][j], tn * st[j]);
        }
    }

    for (i = 1; i < s.length(); ++i) {
        for (j = 0; j < 64; ++j) {
            if (st[j] > INF) {
                break;
            }

            tn = 1;
            ss = 0;
            for (k = i; k > 0; --k) {
                ss = tn * ull(s[k] - '0') + ss;
                tn *= ull(10);
                if ((s[k] == '0') && (k < i)) {
                    continue;
                }

                if (ss > INF) {
                    break;
                }

                if (ull(sqrt(ld(ss))) * ull(sqrt(ld(st[j]))) > MINF) {
                    break;
                }

                if (ss >= n) {
                    break;
                }

                dp[i][j] = min(dp[k - 1][j + 1] + st[j] * ss, dp[i][j]);
            }
        }
    }

    cout << dp[s.length() - 1][0] << endl;
}
