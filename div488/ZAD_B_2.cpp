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

ll p[100010], c[100010];
const int INF = 2E9;

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    set<pair<int, int>> vl;
    vl.insert(mp(INF, INF));

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        vl.insert(mp(-p[i], i));
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        ll ans = c[i];
        auto cur = vl.upper_bound(mp(-p[i], i));
        for (int j = 0; j < k; ++j) {
            if (cur->x == INF) {
                break;
            }
            ans += c[cur->y];
            cur = vl.upper_bound(*cur);
        }
        cout << ans << ' ';
    }

}
