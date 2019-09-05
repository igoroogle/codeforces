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
const ll INF = 1E18;

pair<ll, ll> ar[200010];

bool comp (pair<ll, ll> a, pair<ll, ll> b) {
    return (a.x - a.y > b.x - b.y);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll x, y, n, a, b, sum = 0, ans = 0;

    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ar[i] = mp(x, y);
    }

    sort(ar, ar + n, comp);

    for (ll i = 0; i < min(ll(b - 1), n); ++i) {
        sum += max(ar[i].x, ar[i].y);
    }

    if (b > 0) {
        for (ll i = min(ll(b - 1), n); i < n; ++i) {
            sum += ar[i].y;
        }
    }

    ll cand;
    for (ll i = 0; i < n; ++i) {
        cand = sum;
        if (i < ll(b - 1)) {
            cand -= max(ar[i].x, ar[i].y);
            if (b <= n) {
                cand -= ar[b - 1].y;
                cand += max(ar[b - 1].x, ar[b - 1].y);
            }
        } else {
            cand -= ar[i].y;
        }

        ans = max(ans, cand + max(ar[i].x, ar[i].y));
        ans = max(ans, cand + ar[i].x * (ll(1) << a));
    }

    sum = 0;
    for (ll i = 0; i < min(b, n); ++i) {
        sum += max(ar[i].x, ar[i].y);
    }

    for (ll i = min(b, n); i < n; ++i) {
        sum += ar[i].y;
    }

    ans = max(ans, sum);


    sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += ar[i].y;
    }
    ans = max(ans, sum);

    cout << ans << endl;
}
