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
const ll MOD = 1E9 + 7;
set<int> t;
map<int, int> indx;

int lf[300010], rf[300010], vl[300010];
vector<int> rv[300010];
int dl[300010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> lf[i] >> rf[i];
        t.insert(lf[i]);
        t.insert(rf[i]);
    }

    int m = 0;
    while (!t.empty()) {
        vl[m++] = *t.begin();
        indx[*t.begin()] = m - 1;
        t.erase(t.begin());
    }

    for (int i = 0; i < n; ++i) {
        rv[indx[lf[i]]].pb(indx[rf[i]]);
    }

    ll ans = 0;

    multiset<int> enInd;
    for (int i = 0; i < m; ++i) {
        for (auto cur : rv[i]) {
            if ((!enInd.empty()) && ((ll(vl[i]) + ll(*enInd.begin())) * ll(y) > ll(x))) {
                enInd.clear();
            }

            if (!enInd.empty()) {
                ans = (ans + (ll(vl[i]) + ll(*enInd.begin())) * ll(y)) % MOD;
                enInd.erase(enInd.begin());
            } else {
                ans = (ans + x) % MOD;
            }

            ans = (ans + ll(vl[cur] - vl[i]) * y) % MOD;
            ++dl[cur];
        }

        for (int j = 0; j < dl[i]; ++j) {
            enInd.insert(-vl[i]);
        }
    }

    cout << ans << '\n';
}
