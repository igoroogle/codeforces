#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
map<ll, ll> vl;
int main() {
    ios_base::sync_with_stdio(0);
    ll ans = -INF, n, a, b;
    cin >> n >> a >> b;
    for (ll i = 1; i <= 201; ++i) {
        for (ll j = 1; j <= 201; ++j) {
            for (ll k = 1; k <= 201; ++k) {
                if (i + j != n) {
                    continue;
                }
                if ((i * k <= a) && (j * k <= b)) {
                    ans = max(k, ans);
                }
            }
        }
    }

    cout << ans << endl;
}
