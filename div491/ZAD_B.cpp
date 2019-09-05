#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[111];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, sm = 0;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    sort(a, a + n);
    ll ans = 0, i = 0;
    while (ll(9) * n > ll(2) * sm) {
        ++ans;
        sm -= a[i];
        sm += ll(5);
        ++i;
    }
    cout << ans << endl;
}
