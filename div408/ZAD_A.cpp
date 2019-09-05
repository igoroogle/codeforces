#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1E18;
ll a[110];
int main() {
    ll n, m, k, i, x, ans = INF;
    cin >> n >> m >> k;
    --m;
    for (i = 0; i < n; ++i) {
        cin >> x;
        if ((x > 0) && (x <= k)) {
            ans = min(ll(abs(ll(m - i))) * ll(10), ans);
        }
    }

    cout << ans << endl;
}
