#include <algorithm>
#include <algorithm>
#include <algorithm>
#include <algorithm>
#include <algorithm>
#include <algorithm>
#include <algorithm>
#include <algorithm>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>

#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<ll, ll>> g;
vector<ll> b;
vector<ll> gmn;
vector<ll> gmx;
ll a[100010];
const ll INF = 1E18;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, d, cur = 0, sum = 0, mn = INF, mx = -INF, mnind = -1, mxind = -1, ans = 0;
    cin >> n >> d;
    g.emplace_back(-1, 0);
    b.pb(0);
    gmn.emplace_back(mn);
    gmx.pb(mx);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cur += a[i];
        if (sum + cur > d) {
            cout << -1 << endl;
            cout << i << ' ' << sum << endl;
            return 0;
        }


        if (sum + cur < 0) {
            if (d - (sum + cur - a[i]) + a[i] < 0) {
                cout << -1 << endl;
                return 0;
            }

            sum = sum + cur;
            sum = -sum;
            g.emplace_back(g.back().second, i);
            b.pb(sum);
            gmn.pb(mn);
            gmx.pb(mx);
            mn = INF;
            mx = -INF;
            mnind = -1;
            mxind = -1;
            sum -= cur;
        } else {
            if (cur < mn) {
                mn = cur;
                mnind = i;
            }

            if (cur > mx) {
                mx = cur;
                mxind = i;
            }
        }

        cout << sum << endl;
    }

    b.pb(0);
    gmn.pb(mn);
    gmx.pb(mx);
    sum = 0;
    for (size_t i = 0; i < g.size() - 1; ++i) {
        if ((b[i] + b[i + 1] <= d) && (gmx[i + 1] + b[i + 1] <= d)) {
            b[i + 1] += b[i];
            continue;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
