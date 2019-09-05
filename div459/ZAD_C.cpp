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
int dp[5003][5003], n;
string s;

int get(int kl, int l, int r) {
    if (l > r) {
        return 0;
    }

    if (dp[kl][l][r] != 0) {
        if (dp[kl][l][r] == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    if (kl == 0) {
        if ((r - l + 1) % 2) {
            dp[kl][l][r] = -1;
            return 0;
        }

        if ((s[l] == ')') || (s[r] == '(')) {
            dp[kl][l][r] = -1;
            return 0;
        }

        if (l + 1 == r) {
            dp[kl][l][r] = 1;
            return 1;
        }

        if (get(kl, l + 1, r - 1) || get(1, l + 1, r)) {
            dp[kl][l][r] = 1;
            return 1;
        } else {
            dp[kl][l][r] = 0;
            return 0;
        }
    }

    if ()
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = s.length();
    int ans = 0;
    for (int kl = 1; kl <= n; ++i) {
        for (i = 0; i < n - kl + 1; ++j) {
            if ()
        }
    }
    cout << ans << endl;
}
