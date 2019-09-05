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
const ll INF = 2E18;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y, d;
        cin >> n >> x >> y >> d;
        ll ans  = INF;
        if (abs(ll(1) - y) % d == ll(0)) {
            ll vans = abs(ll(1) - x) / d;
            if (abs(ll(1) - x) % d) {
                ++vans;
            }
            vans += abs(ll(1) - y) / d;
            ans = min(ans, vans);
        }

        if (abs(ll(n) - y) % d == ll(0)) {
            ll vans = abs(ll(n) - x) / d;
            if (abs(ll(n) - x) % d) {
                ++vans;
            }
            vans += abs(ll(n) - y) / d;
            ans = min(ans, vans);
        }

        if (abs(x - y) % d == 0) {
            ans = min(ans, abs(x - y) / d);
        }

        if (ans == INF) {
            ans = -1;
        }

        cout << ans << '\n';
    }
}
