#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[410];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, x, ans = 360, sum;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; ++i) {
        sum = 0;
        for (ll j = i; j < n; ++j) {
            sum += a[j];
            ans = min(ans, abs(360 - sum - sum));
        }
    }
    cout << ans << endl;
}
