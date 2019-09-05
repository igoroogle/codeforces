#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[3][100010], a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i, ans = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ans = abs(a[0] - a[1]);
    dp[0][0] = ans;
    for (i = 1; i < n; ++i) {
        dp[0][i] = max(dp[1][i - 1] + abs(a[i - 1] - a[i]), ll(0));
        dp[1][i] = max(dp[0][i - 1] - abs(a[i - 1] - a[i]), ll(0));
        ans = max(max(dp[0][i], dp[1][i]), ans);
    }

    cout << ans << endl;
}
