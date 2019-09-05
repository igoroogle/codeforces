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
typedef pair<int, int> pii;
const int INF = 1E9 + 7;
const int LEN = 252;
vector<char> a[3];
int next_let[26][100002], last_let[26];
int dp[LEN][LEN][LEN];

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            for (int k = 0; k < LEN; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    int n, q;
    string s;
    cin >> n >> q >> s;
    fill(last_let, last_let + 26, INF);
    dp[0][0][0] = 0;
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            next_let[j][i] = last_let[j];
        }
        if (i > 0) {
            last_let[s[i - 1] - 'a'] = i;
        }
    }

    while(q--) {
        char c;
        cin >> c;
        if (c == '+') {
            int t;
            char new_let;
            cin >> t >> new_let;
            --t;
            a[t].pb(new_let);
            int st_i = 0, st_j = 0, st_k = 0;
            if (t == 0) {
                st_i = a[t].size();
            } else if (t == 1) {
                st_j = a[t].size();
            } else {
                st_k = a[t].size();
            }


            for (int i = st_i; i <= int(a[0].size()); ++i) {
                for (int j = st_j; j <= int(a[1].size()); ++j) {
                    for (int k = st_k; k <= int(a[2].size()); ++k) {
                        if ((i > 0) && (dp[i - 1][j][k] != INF)) {
                            dp[i][j][k] = min(dp[i][j][k], next_let[a[0][i - 1] - 'a'][dp[i - 1][j][k]]);
                        }

                        if ((j > 0) && (dp[i][j - 1][k] != INF)) {
                            dp[i][j][k] = min(dp[i][j][k], next_let[a[1][j - 1] - 'a'][dp[i][j - 1][k]]);
                        }

                        if ((k > 0) && (dp[i][j][k - 1] != INF)) {
                            dp[i][j][k] = min(dp[i][j][k], next_let[a[2][k - 1] - 'a'][dp[i][j][k - 1]]);
                        }
                    }
                }
            }
        } else {
            int t;
            cin >> t;
            --t;
            char old_let = a[t].back();
            int st_i = 0, st_j = 0, st_k = 0;

            if (t == 0) {
                st_i = a[t].size();
            } else if (t == 1) {
                st_j = a[t].size();
            } else {
                st_k = a[t].size();
            }

            for (int i = st_i; i <= int(a[0].size()); ++i) {
                for (int j = st_j; j <= int(a[1].size()); ++j) {
                    for (int k = st_k; k <= int(a[2].size()); ++k) {
                        dp[i][j][k] = INF;
                    }
                }
            }
            a[t].pop_back();
        }

        if (dp[a[0].size()][a[1].size()][a[2].size()] == INF) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
