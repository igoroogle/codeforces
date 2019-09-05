#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll fac[200010];
ll binpow(ll a, ll n) {
    if (n == 0) {
        return ll(1);
    }

    if (n == 1) {
        return (a % MOD);
    }

    ll ans = binpow(a, n >> ll(1));
    ans = (ans * ans) % MOD;
    if (n & ll(1)) {
        ans = (ans * (a % MOD)) % MOD;
    }

    return ans;
}

string s;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i, x = 0, y = 0, ans = 0, val;
    cin >> s;
    n = s.length();
    fac[0] = 1;
    for (i = 1; i <= n; ++i) {
        fac[i] = (fac[i - 1] * ll(i)) % MOD;
    }

    for (i = 0; i < n; ++i) {
        if (s[i] == ')') {
            ++y;
        }
    }

    for (i = 0; i < n; ++i) {
        if (s[i] == ')') {
            --y;
            continue;
        }

        ++x;
        if (y == 0) {
            continue;
        }

        val = (fac[x + y - 1] * binpow(fac[x] * fac[y - 1], ll(MOD - 2))) % MOD;
        ans = (ans + val) % MOD;
    }

    cout << ans << endl;
}
