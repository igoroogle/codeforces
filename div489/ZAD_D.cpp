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
const ll MDL = 3E9;
const ll DL = 2E18 + 1;
ll a[200010], vl[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vl[i] = vl[i - 1] + a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll p = 1;
        for (int j = i; j <= n; ++j) {
            if (ll(sqrt(ld(p)) * sqrt(ld(a[j]))) > MDL) {
                break;
            }

            p *= a[j];
            if (p > DL) {
                break;
            }
            ll sum = vl[j] - vl[i - 1];
            if (sum * k == p) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
}
