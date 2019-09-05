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
const ll MOD = 998244353;
const ll DL = 1000010;
ll f[DL], dp[DL];
int main() {
    ios_base::sync_with_stdio(0);
    f[0] = 1;
    for (int i = 1; i < DL; ++i) {
        f[i] = (f[i - 1] * ll(i)) % MOD;
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < DL; ++i) {
        dp[i] = (dp[i - 1] + (f[i - 1] + MOD - 1)) % MOD;
        dp[i] = (i * dp[i]) % MOD;
    }

    int n;
    cin >> n;
    cout << dp[n] << endl;
}
