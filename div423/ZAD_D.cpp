#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const int INF = 1E9;
const int DL = 3000003;
string val[3000010];
vector<int> a[2];
vector<pair<int, int>> an;
int main() {
    ios_base::sync_with_stdio(0);
    ll ans = 0, vt = 0, cur;
    ll n, k, i;
    cin >> n >> k;
    for (i = 1; i <= k; ++i) {
        a[0].pb(i);
    }

    cur = k + 1;
    ans = 1;
    while (cur <= n) {
        ++ans;
        a[1 - vt].clear();
        for (i = 0; i < a[vt].size(); ++i) {
            if (cur > n) {
                an.pb(mp(n, a[vt][i]));
            } else {
                an.pb(mp(cur, a[vt][i]));
                a[1 - vt].pb(cur);
                ++cur;
            }
        }
        vt = 1 - vt;
    }

    if (a[vt].size() < 3) {
        if (a[vt].size() > 1) {
            ++ans;
        }
        for (i = 0; i < a[vt].size() - 1; ++i) {
            an.pb(mp(a[vt][i], a[vt][i + 1]));
        }
    } else {
        ++ans;
        for (i = an.size() - 1; i >= 0; --i) {
            if (an[i].x != n) {
                break;
            } else {
                an[i].x = n - 1;
            }
        }

        for (i = 0; i < a[vt].size() - 1; ++i) {
            an.pb(mp(n, a[vt][i]));
        }
    }

    cout << ans << endl;
    for (i = 0; i < an.size(); ++i) {
        cout << an[i].x << ' ' << an[i].y << endl;
    }
    return 0;
}
