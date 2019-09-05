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
ll a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, c;
    cin >> n >> c;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 0;
    for (ll i = 0; i < n % c; ++i) {
        ans += a[i];
    }

    for (ll i = n % c; i < n; ++i) {
        ans += a[i];
    }
    cout << ans << endl;
}
