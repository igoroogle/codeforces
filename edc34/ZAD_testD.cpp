#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll P = 239;
const ll MOD = 3000000019;
const ll DL = 5010;
ll hashes[DL], pw[DL];
ll k, m;
inline void buildHash(const string& s, ll n) {
    hashes[0] = 0;
    for (ll i = 0; i < n; ++i) {
        hashes[i + 1] = (hashes[i] * P + ll(s[i] - 'a' + 1)) % MOD;
    }
}

ll getHash(ll l, ll r) {
    ll ans = (hashes[l - 1] * pw[r - l + 1]) % MOD;
    ans = (hashes[r] + MOD - ans) % MOD;
    return ans;
}

ll hashSwap(const string& s, ll i, ll j, ll n) {
    ll ansl = ll(s[j] - 'a' + 1) + hashes[i] * P;
    if (i + 1 < j) {
        ansl = (ansl * pw[j - i - 1]) % MOD;
        ansl = (ansl + getHash(i + 2, j)) % MOD;
    }
    ll ansr = ll(s[i] - 'a' + 1);
    if (j < n - 1) {
        ansr = (ansr * pw[n - j - 1]) % MOD;
        ansr = (ansr + getHash(j + 2, n)) % MOD;
    }
    return (ansl * pw[n - j] + ansr) % MOD;
    /*string t = s;
    swap(t[i], t[j]);
    buildHash(t, n);
    ll ans = hashes[n];
    buildHash(s, n);
    return ans;*/
}


ll a[200010];
int main() {
    freopen("input.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    ll n = 200000;
    cout << n << endl;
    a[n - 1] = 1E9;
    for (ll i = n - 2; i >= 0; --i) {
        a[i] = a[i + 1] - 10000;
    }
    for (ll i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
}
