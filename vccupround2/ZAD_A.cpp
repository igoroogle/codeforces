#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF = 1E16;
const ld EPS = 1E-8;
ll a, b, n, p;
pair<ld, pair<ll, ll>> an[100010];
void prov() {
    ld zap = an[0].x * p, vv;
    ll val = an[0].y.x, i;
    for (i = 1; i < n; ++i) {
        if (val <= p) {
            zap += (an[i].x - an[i - 1].x) * ld(p - val);
            val += an[i].y.x;
            continue;
        } else {
            vv = (an[i].x - an[i - 1].x) * ld(val - p);
            if (zap > vv) {
                zap -= vv;
                val += an[i].y.x;
                continue;
            } else {
                cout << fixed << setprecision(11) << an[i - 1].x + (zap / (val - p)) << endl;
                exit(0);
            }
        }
    }

    if (val <= p) {
        cout << -1 << endl;
        exit(0);
    }

    cout << fixed << setprecision(11) << an[n - 1].x + (zap / (val - p)) << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll i;
    cin >> n >> p;
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        an[i] = mp(ld(b) / ld(a), mp(a, b));
    }

    sort(an, an + n);
    prov();
}
