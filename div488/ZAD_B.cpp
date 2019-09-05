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
pair<pair<ll, ll>, ll> a[100010];
ll ans[100010];

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].x.x;
        a[i].x.y = i;
    }

    for (ll i = 0; i < n; ++i) {
        cin >> a[i].y;
    }

    sort(a, a + n);
    ll sum = 0;
    set<ll> vl;
    for (ll i = 0; i < n; ++i) {
        vl.insert(a[i].y);
        sum += a[i].y;
        ans[a[i].x.y] = sum;
        if (vl.size() > k) {
            cout << i << ' ' << *vl.begin() << endl;
            sum -= *vl.begin();
            vl.erase(vl.begin());
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}
