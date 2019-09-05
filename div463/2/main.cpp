#include<algorithm>
#include<map>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
const ll DL = 1000003;
ll ans[DL], vans[DL];
vector<pair<pair<ll, ll>, ll>> r1[DL];
vector<ll> l1[DL];
map<pair<ll, ll>, ll> t;
    ll g(ll n) {
    if (n < 10) {
        return n;
    }
    ll ans = 1;
    while (n > 0) {
        if (n % 10 != 0) {
            ans *= n % 10;
        }
        n /= 10;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    ll i, n, lf, rf, k;
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> lf >> rf >> k;
        l1[lf - 1].emplace_back(k);
        r1[rf].push_back(mp(mp(lf - 1, k), i));
    }

    for (int i = 0; i < DL; ++i) {
        ++ans[g(i)];
        sort(l1[i].begin(), l1[i].end());
        for (size_t j = 0; j < l1[i].size(); ++j) {
            if ((j + 1 < l1[i].size()) && (l1[i][j] == l1[i][j + 1])) {
                continue;
            }
            t[mp(i, l1[i][j])] += ans[l1[i][j]];
        }

        for (auto cur : r1[i]) {
            vans[cur.y] = ans[cur.x.y] - t[cur.x];
        }
    }


    for (int i = 0; i < q; ++i) {
        cout << vans[i] << '\n';
    }
}
