#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010], lg[100010], rg[100010], dp[100010], vl[100010], lf[100010], rf[100010], ans = 0;


int main() {
    ios_base::sync_with_stdio(0);
    ll n, x, k, vl = 0;
    cin >> n >> x >> k;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    ll l = 0, r = 0;
    while (r < n) {
        vl = a[r] / x - (a[l] - 1) / x;
        while ((l <= r) && (vl > k)) {
            vl = a[r] / x - (a[l] - 1) / x;
            ++l;
        }

        if (vl == k) {
            ++ans;
        }

        ++r;
    }
    cout << ans << endl;
}
