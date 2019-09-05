#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef unsigned int uni;
typedef long long ll;
typedef long double ld;
const int DL = 200010;
bool use[DL];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, vl1 = 0, vl2 = 0, a, b, sm = 0;
    cin >> a >> b;
    for (int i = 1; i < DL; ++i) {
        if (sm + ll(i) > a + b) {
            n = i - 1;
            break;
        }
        sm += ll(i);
    }

    vector<ll> ans;
    for (ll i = n; i > 0; --i) {
        if (i <= a) {
            use[i] = true;
            ans.pb(i);
            a -= i;
        }
    }

    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur << ' ';
    }
    cout << '\n';

    cout << n - int(ans.size()) << '\n';
    for (int i = 1; i <= n; ++i) {
        if (!use[i]) {
            cout << i << ' ';
        }
    }
}
