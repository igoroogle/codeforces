#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef unsigned int uni;
typedef long long ll;
typedef long double ld;
int dp[2003][2003];
char a[2003][2003];
bool use[2003][2003];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    if (a[0][0] != 'a') {
        dp[0][0] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0) && (j == 0)) {
                continue;
            }

            dp[i][j] = n + 1;
            if (i - 1 >= 0) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            }

            if (j - 1 >= 0) {
                dp[i][j] = min(dp[i][j - 1], dp[i][j]);
            }

            if (a[i][j] != 'a') {
                ++dp[i][j];
            }
        }
    }


    if (dp[n - 1][n - 1] <= k) {
        for (int i = 0; i < n + n - 1; ++i) {
            cout << 'a';
        }
        cout << '\n';
        return 0;
    }

    string ans;
    ans.reserve(n + n - 1);

    int vl = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] != k) {
                continue;
            }

            if (i + j > vl) {
                vl = i + j;
            }
        }
    }


    if (k > 0) {
        for (int i = 0; i <= vl; ++i) {
            ans.pb('a');
        }
    }

    queue<pair<int, int>> q;
    char mn = 'a';

    if (k > 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((dp[i][j] != k) || (i + j != vl)) {
                    continue;
                }
                q.push(mp(i, j));
                use[i][j] = true;
                a[i][j] = 'a';
            }
        }
    } else {
        q.push(mp(0, 0));
        use[0][0] = 0;
        mn = a[0][0];
        vl = 0;
        ans.pb(a[0][0]);
    }

    while (vl < n + n - 2) {
        char mnN = 'z';
        while ((!q.empty()) && (vl == q.front().x + q.front().y)) {
            auto zn = q.front();
            q.pop();
            if (a[zn.x][zn.y] != mn) {
                continue;
            }

            if ((!use[zn.x + 1][zn.y]) && (zn.x + 1 < n)) {
                q.push(mp(zn.x + 1, zn.y));
                mnN = min(mnN, a[zn.x + 1][zn.y]);
                use[zn.x + 1][zn.y] = true;
            }

            if ((!use[zn.x][zn.y + 1]) && (zn.y + 1 < n)) {
                q.push(mp(zn.x, zn.y + 1));
                mnN = min(mnN, a[zn.x][zn.y + 1]);
                use[zn.x][zn.y + 1] = true;
            }
        }
        mn = mnN;
        ans.pb(mn);
        ++vl;
    }

    cout << ans << '\n';
}
