#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int LEN = 1048579;

bool use[42][42], puse[42];
int dp[LEN], usd[LEN], bits[LEN];

int main() {
    ios_base::sync_with_stdio(0);
    /*for (int i = 0; i < 42; ++i) {
        for (int j = 0; j < 42; ++j) {
            use[i][j] = true;
        }
    }*/

    bits[0] = 0;
    for (int i = 1; i < LEN; ++i) {
        bits[i] = (1 & i) + bits[i >> 1];
    }

    map<string, int> dd;
    int kl = 0;
    int n, m;
    cin >> n >> m;
    bool past = true;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            if (past) {
                continue;
            }

            for (int j = 0; j < m; ++j) {
                for (int k = j + 1; k < m; ++k) {
                    if ((puse[k]) && (puse[j])) {
                        use[k][j] = true;
                        use[j][k] = true;
                    }
                }
            }
            fill(puse, puse + m, false);
            past = true;
            continue;
        }

        past = false;
        string s;
        cin >> s;
        int ind = 0;
        if (dd[s] == 0) {
            ind = ++kl;
            dd[s] = ind;
        } else {
            ind = dd[s];
        }

        puse[ind - 1] = true;
    }

    /*for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i << ' ' << j << ' ' << use[i][j] << endl;
        }
    }*/

    int p1 = min(m, 20);
    int p2 = m - p1;
    for (int bit = 0; bit < (1 << p1); ++bit) {
        usd[bit] = true;
        for (int i = 0; i < p1; ++i) {
            if (!usd[bit]) {
                break;
            }
            if ((1 << i) & bit) {
                for (int j = 0; j < p1; ++j) {
                    if (i == j) {
                        continue;
                    }

                    if ((1 << j) & bit) {
                        if (use[i][j]) {
                            usd[bit] = false;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int bit = 0; bit < (1 << p1); ++bit) {
        dp[bit] = 0;
        if (usd[bit]) {
            dp[bit] = bits[bit];
            continue;
        }

        for (int i = 0; i < p1; ++i) {
            if ((1 << i) & bit) {
                dp[bit] = max(dp[bit], dp[bit ^ (1 << i)]);
            }
        }
    }


    int ans = 0;
    for (int bit = 0; bit < (1 << p1); ++bit) {
        ans = max(ans, dp[bit]);
    }

    if (p2 == 0) {
        cout << ans << '\n';
        return 0;
    }

    for (int bit = 0; bit < (1 << p2); ++bit) {
        bool f = true;
        for (int i = 0; i < p2; ++i) {
            if (!f) {
                break;
            }
            if ((1 << i) & bit) {
                for (int j = 0; j < p2; ++j) {
                    if (i == j) {
                        continue;
                    }

                    if ((1 << j) & bit) {
                        if (use[i + p1][j + p1]) {
                            f = false;
                            break;
                        }
                    }
                }
            }
        }

        if (!f) {
            continue;
        }

        int mask = (1 << p1) - 1;
        for (int i = 0; i < p1; ++i) {
            for (int j = 0; j < p2; ++j) {
                if ((1 << j) & bit) {
                    if (use[i][j + p1]) {
                        mask ^= (1 << i);
                        break;
                    }
                }
            }
        }

        ans = max(ans, bits[bit] + dp[mask]);
    }

    cout << ans << '\n';
}
