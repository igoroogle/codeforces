#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ll, pair<ll, ll>> a[200010];
ll vl1[200010], vl2[200010];
int main() {
    ll n, k, ans = 0, i, x, y;
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &vl1[i]);
    }

    for (i = 0; i < n; ++i) {
        scanf("%I64d", &vl2[i]);
    }

    for (i = 0; i < n; ++i) {
        x = vl1[i];
        y = vl2[i];
        a[i] = mp(x - y, mp(x, y));
    }

    sort(a, a + n);
    for (i = 0; i < k; ++i) {
        ans += a[i].y.x;
    }

    for (i = k; i < n; ++i) {
        ans += min(a[i].y.x, a[i].y.y);
    }

    cout << ans << endl;
}
