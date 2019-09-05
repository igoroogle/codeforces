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
ll kl[1008], vl[1008];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        kl[i] = n / m;
        if ((i != ll(0)) && (n % m >= i)) {
            ++kl[i];
        }
    }

    for (ll i = 0; i < m; ++i) {
        vl[(i * i) % m] += kl[i];
    }


    ll ans = 0;
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < m; ++j) {
            if ((i + j) % m == ll(0)) {
                ans += vl[i] * vl[j];
            }
        }
    }

    cout << ans << '\n';
}
