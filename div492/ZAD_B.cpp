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
int a[117], dp[103][103][103];

int rec(int l, int r, int k) {
    if (dp[l][r][k] != -1) {
        return dp[l][r][k];
    }

    if (l == r) {
        dp[l][r][k] = 0;
        return 0;
    }

    if (l + 1 == r) {
        dp[l][r][k] = 01;
        if (abs(a[l] - a[r]) <= k) {
            dp[l][r][k] = 1;
        }
        return dp[l][r][k];
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }

    cout << rec(0, n - 1, b) << endl;
}
