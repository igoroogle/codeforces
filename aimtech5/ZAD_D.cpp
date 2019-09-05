#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ll MOD = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    vector<pair<pair<ll, ll>, ll>> a, b;
    set<ll> tp, tm;
    tp.insert(-INF);
    tp.insert(INF);
    tm.insert(-INF);
    tm.insert(INF);

    a.pb(mp(mp(-INF, INF), ll(1)));
    string s;
    int n;
    ll vl;
    cin >> n;
    while (n--) {
        cin >> s >> vl;
        if (s == "ADD") {
            b.clear();
            for (auto cur : a) {
                if (cur.x.x < vl) {
                    b.pb(cur);
                    b.back().x.y = min(vl, b.back().x.y);
                }

                if (cur.x.y > vl) {
                    b.pb(cur);
                    b.back().x.x = max(vl, b.back().x.x);
                }
            }
            sort(b.begin(), b.end());
            a.clear();
            if (!b.empty()) {
                a.pb(b.front());
            }

            for (size_t i = 1; i < b.size(); ++i) {
                if (a.back().x == b[i].x) {
                    a.back().y = (a.back().y + b[i].y) % MOD;
                } else {
                    a.pb(b[i]);
                }
            }
            tp.insert(vl);
            tm.insert(-vl);
        } else {
            int i = 0;
            while (i < int(a.size())) {
                if (a[i].x.x == vl) {
                    a[i].x.x = -(*tm.upper_bound(-vl));
                    ++i;
                } else if (a[i].x.y == vl) {
                    a[i].x.y = (*tp.upper_bound(vl));
                    ++i;
                } else {
                    a.erase(a.begin() + i);
                }
            }
            tp.erase(vl);
            tm.erase(-vl);
        }
        /*for (auto cur : a) {
            cout << cur.x.x << ' ' << cur.x.y << ' ' << cur.y << endl;
        }*/
    }

    ll ans = 0;
    for (auto cur : a) {
        ans = (ans + cur.y) % MOD;
    }
    cout << ans  << '\n';
    cout << a.size() << endl;
}
