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
map<ll, ll> an;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, x, ans = 0;
    cin >> n >> m;
    ll s = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        s += x;
        ++an[s];
    }

    s = 0;
    for (ll i = 0; i < m; ++i) {
        cin >> x;
        s += x;
        ans += an[s];
    }
    cout << ans << endl;
}
