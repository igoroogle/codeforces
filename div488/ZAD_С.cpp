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
ll x[5], y[5], x2[5], y2[5], toans = 0;

ll vec(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 * y2 - x2 * y1);
}

ll prov(ll xs, ll ys) {
    ll ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += vec(x[i + 1] - x[i], y[i + 1] - y[i], xs - x[i], ys - y[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 4; ++i) {
        cin >> x[i] >> y[i];
    }
    x[4] = x[0];
    y[4] = y[0];

    toans = prov(x[0], y[0]);
    //cout << toans << endl;

    for (int i = 0; i < 4; ++i) {
        cin >> x2[i] >> y2[i];
        if (prov(x2[i], y2[i]) == toans) {
            cout << "YES\n";
            return 0;
        }
    }

    x2[4] = x2[0];
    y2[4] = y2[0];
    for (int i = 0; i < 5; ++i) {
        swap(x[i], x2[i]);
        swap(y[i], y2[i]);
    }

    toans = prov(x[0], y[0]);
    for (int i = 0; i < 4; ++i) {
        if (prov(x2[i], y2[i]) == toans) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
