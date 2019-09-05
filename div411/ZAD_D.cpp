#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll MOD = 1E9 + 7;
char s[1000010];
ll dp[1000010];
int main() {
    //ios_base::sync_with_stdio(0);
    ll n, i, kl = 0, ans = 0;
    scanf("%s", &s);
    n = strlen(s);
    dp[0] = 0;
    dp[1] = 1;
    for (i = 2; i <= n; ++i) {
        dp[i] = (ll(1) + dp[i - 1] * ll(2)) % MOD;
    }

    for (i = 0; i < n; ++i) {
        if (s[i] == 'b') {
            ans = (ans + dp[kl]) % MOD;
        } else {
            ++kl;
        }
    }

    cout << ans << endl;
    return 0;
}
