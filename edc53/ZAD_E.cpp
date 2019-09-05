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
const ll MOD = 998244353;
int bits[1 << 11];
ll dp[20][1 << 11], val[20][1 << 11];


ll binpow(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

ll getval(ll n, ll k) {
    vector<ll> st;
    if (n == 0) {
        return 1;
    }

    while (n > 0) {
        st.pb(n % ll(10));
        n /= ll(10);
    }
    reverse(st.begin(), st.end());
    ll ans = 0;
    for (size_t i = 1; i < st.size(); ++i) {
        for (int bit = 0; bit < (1 << 10); ++bit) {
            if (bits[bit] > k) {
                continue;
            } else {
                ans = (ans + dp[i][bit]) % MOD;
                if ((i > 1) && (bit & 1)) {
                    ans = (ans + MOD - dp[i - 1][bit]) % MOD;
                    ans = (ans + MOD - dp[i - 1][bit ^ 1]) % MOD;
                }
            }
        }
    }

    int bit = 0;
    ll sum = 0, valt = 0, valts = 0;
    for (int i = 0; i < int(st.size()); ++i) {
        valt = (binpow(ll(10), ll(int(st.size()) - i - 1)));
        for (int j = 0; j < st[i]; ++j) {
            if ((j == 0) && (i == 0) && (int(st.size() > 1))) {
                continue;
            }

            int bitt = (bit | (1 << j));
            valts = (valt * ll(st[i])) % MOD;
            valts = (valts + sum) % MOD;

            if (i + 1 == int(st.size())) {
                if (bits[bitt] <= k) {
                    ans = (ans + valts) % MOD;
                }
                continue;
            }

            for (int p = 0; p < (1 << 10); ++p) {
                if (bits[p | bitt] <= k) {
                    ans = (ans + dp[int(st.size()) - i - 1][p]) % MOD;
                    ans = (ans + val[int(st.size()) - i - 1][p] * valts) % MOD;
                }
            }
        }

        bit |= (1 << st[i]);
        valts = (valt * ll(st[i])) % MOD;
        sum = (sum + valts) % MOD;
    }

    if (bits[bit] <= k) {
        ans = (ans + sum) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 1; i < (1 << 11); ++i) {
        bits[i] = (bits[i >> 1]) + (i & 1);
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j < (1 << 10); ++j) {
            for (int p = 1; p < 10; ++p) {
                for (int pos = 0; pos < i; ++pos) {
                    ll ans = (binpow(ll(10), ll(pos)) * binpow(bits[j], ll(i - 1))) % MOD;
                    ans = (ans * ll(p)) % MOD;
                    dp[i][j] = (dp[i][j] + ans) % MOD;
                }
            }

            int bit = (j & (j - 1));
            while (bit > 0) {
                dp[i][j] = (dp[i][j] + MOD - dp[i][bit]) % MOD;
                bit = (bit - 1) & j;
            }
        }
    }


    for (int i = 0; i < 20; ++i) {
        for (int j = 1; j < (1 << 10); ++j) {
            val[i][j] = binpow(bits[j], i);
            int bit = (j & (j - 1));
            while (bit > 0) {
                val[i][j] = (val[i][j] + MOD - val[i][bit]) % MOD;
                bit = (bit - 1) & j;
            }
        }
    }

    ll l, r, k;
    //cout << getval(100, 10) << endl;
    cin >> l >> r >> k;
    cout << (getval(r, k) + MOD - getval(l - ll(1), k)) % MOD << '\n';
    //cout << getval(50, 2) << endl;
    //cout << getval(10, 10) << endl;
}
