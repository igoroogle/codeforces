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
const ll INF = 1E18;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, a, b, c, t, x, ans = 0, mn, vl;
    cin >> n >> a >> b >> c >> t;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        mn = a;
        vl = a;
        for (ll j = x + 1; j <= t; ++j) {
            vl += (c - b);
            mn = max(mn, vl);
        }
        ans += mn;
    }
    cout << ans << endl;
}
