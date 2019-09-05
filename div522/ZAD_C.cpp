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
bool dp[100003][6];
int pr[100003][6];
int a[200010];
int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 5; ++i) {
        dp[0][i] = true;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            pr[i][j] = -1;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (!dp[i - 1][j]) {
                continue;
            }

            for (int k = 0; k < 5; ++k) {
                if ((k == j) || (dp[i][k])) {
                    continue;
                }
                if (a[i - 1] == a[i]) {
                    dp[i][k] = true;
                    pr[i][k] = j;
                    continue;
                }

                if ((a[i - 1] < a[i]) && (j < k)) {
                    dp[i][k] = true;
                    pr[i][k] = j;
                    continue;
                }

                if ((a[i - 1] > a[i]) && (j > k)) {
                    dp[i][k] = true;
                    pr[i][k] = j;
                    continue;
                }
            }
        }
    }


    int ind = -1;
    for (int i = 0; i < 5; ++i) {
        if (dp[n - 1][i]) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        ans.pb(ind);
        ind = pr[i][ind];
    }

    reverse(ans.begin(), ans.end());
    for (auto cur : ans) {
        cout << cur + 1 << ' ';
    }
}
