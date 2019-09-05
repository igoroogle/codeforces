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
const ll INF = 1E18 + 3;
const ll DL = 31623;
ll a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, x;
    cin >> n >> k;
    for (ll i = 0; i < k; ++i) {
        cin >> a[i];
    }
    auto ans = mp(ll(0), ll(0));
    for (ll i = 0; i < k; ++i) {
        if (a[ans.x] * ans.y < n / a[i] * a[i]) {
            ans = mp(i, n / a[i]);
        }
    }

    cout << ans.x + ll(1) << ' ' << ans.y << endl;
}
