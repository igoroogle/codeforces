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
const ll MOD = 1E9 + 7;
const int LEN = 10001;
const int ST = 51;
int dp[ST][ST][LEN];
ll ans[ST][ST], rev[ST], vans = 0;
vector<pair<ll, int>> ar;
vector<ll> ars;

ll binpow (ll a, int n) {
	ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }
		a = (a * a) % MOD;
		n >>= 1;
	}
	return ans;
}

/*void rec(ll cans, ll rans, int ind) {
    //cout << ind << endl;
    if (ind == int(ar.size())) {
        vans = (vans + cans *  rans) % MOD;
        return;
    }

    ll p = rans;
    for (int i = 0; i <= ar[i].y; ++i) {
        //cout << ans[ar[i].y][i] << endl;
        rec((cans * ans[ar[ind].y][i]) % MOD, p, ind + 1);
        p = (p * ar[ind].x) % MOD;
        //rec(1, ind + 1);
    }
}*/

void rec(ll cans, ll rans, int ind) {
    //cout << ind << endl;
    if (ind == int(ars.size())) {
        vans = (vans + cans *  rans) % MOD;
        return;
    }

    ll p = rans;
    for (int i = 0; i <= 1; ++i) {
        rec((cans * ans[1][i]) % MOD, p, ind + 1);
        p = (p * ars[ind]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < ST; ++i) {
        rev[i] = binpow(ll(i + 1), int(MOD - 2));
    }

    for (int i = 0; i < ST; ++i) {
        dp[i][i][0] = 1;
        for (int k = 1; k < LEN; ++k) {
            dp[i][i][k] = (ll(dp[i][i][k - 1]) * rev[i]) % MOD;
            for (int j = i - 1; j >= 0; --j) {
                dp[i][j][k] = (ll(dp[i][j][k - 1]) * rev[j]) % MOD;
                dp[i][j][k] = (ll(dp[i][j][k]) + ll(dp[i][j + 1][k])) % MOD;
            }
        }
    }

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < ST; ++i) {
        for (int j = 0; j < ST; ++j) {
            ans[i][j] = dp[i][j][k];
        }
    }

    ll m = n, i = 2;
    while ((m > ll(1)) && (i * i <= m)) {
        if (m % i == 0) {
            ar.em(i, 0);
            while (m % i == 0) {
                m /= i;
                ++ar.back().y;
                ars.pb(ar.back().x);
            }
        }
        ++i;
    }

    if (m > ll(1)) {
        ar.em(m, 1);
        ars.pb(m);
    }

    /*for (auto cur : ar) {
        cout << cur.x << ' ' << cur.y << ' ';
    }
    cout << endl;*/
    rec(ll(1), ll(1), 0);
    cout << vans << '\n';
    return 0;
}
