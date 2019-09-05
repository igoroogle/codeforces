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
ll a[17], b[17];

int main() {
    ios_base::sync_with_stdio(0);
    ll n = 14, ans = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            b[j] = a[j];
        }
        b[i] = 0;
        for (ll j = 0; j < n; ++j) {
            b[j] += a[i] / n;
        }

        for (ll j = 1; j <= a[i] % n; ++j) {
            ++b[(i + j) % n];
        }

        ll sm = 0;
        for (ll j = 0; j < n; ++j) {
            if (!(b[j] % 2)) {
                sm += b[j];
            }
        }
        ans = max(ans, sm);
    }

    cout << ans << endl;
}
