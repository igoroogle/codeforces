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
const ll INF = 2E18;
vector<ll> vl[100010];
ll ans[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        --x;
        vl[x].pb(y);
    }

    ll vans = 0;
    for (int i = 0; i < m; ++i) {
        if (vl[i].empty()) {
            continue;
        }

        sort(vl[i].begin(), vl[i].end());
        reverse(vl[i].begin(), vl[i].end());
        ll sum = 0;
        for (int j = 0; j < int(vl[i].size()); ++j) {
            sum += vl[i][j];
            if (sum <= 0) {
                break;
            }

            ans[j] += sum;
            vans = max(ans[j], vans);
        }
    }

    cout << vans << '\n';
}
