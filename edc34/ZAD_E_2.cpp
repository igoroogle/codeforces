#include<iostream>
#include<iomanip>
#include<algorithm>
#include<map>
#include<unordered_map>
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

map<ll, ll> gt;
inline void getstr(const string& s, ll n) {
    buildHash(s, n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (k == m - 2) {
                gt[hashSwap(s, i, j, n)] = k + 1;
                //cout << "sldfj\n";
                continue;
            }
            auto vl = gt.find(hashSwap(s, i, j, n));
            if ((vl == gt.end()) || (vl->second != k + 2)) {
                continue;
            } else {
                vl->second = k + 1;
                //cout << "lsjdlk\n";
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    pw[0] = 1;
    for (ll i = 1; i < DL; ++i) {
        pw[i] = (pw[i - 1] * P) % MOD;
    }
    ll n;
    cin >> k >> n;
    m = k;
    string s;
    --k;
    while (k--) {
        cin >> s;
        getstr(s, n);
    }
    cin >> s;
    buildHash(s, n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            //cout << i << ' ' << j << ' ' << gt[hashSwap(s, i, j, n)] << endl;
            if ((gt[hashSwap(s, i, j, n)] == 1) || (m == 1)) {
                swap(s[i], s[j]);
                cout << s << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}
