#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll dp[1000010];

int main() {
    ll n, ans = 0;
    cin >> n;
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;
    for (ll i = 3; i <= 89; ++i) {
        dp[i] = min(dp[i - 1] * ll(2), dp[i - 1] + dp[i - 2]);
    }




    cout << ans << endl;
    return 0;
}
