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
ll e[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, u;
    cin >> n >> u;
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }

    ll l = 0;
    ld ans = -1;
    bool f = false;
    for (int i = 2; i < n; ++i) {
        while (e[i] - e[l] > u) {
            ++l;
        }
        if (i - l < 2) {
            continue;
        }
        f = true;
        ans = max(ld(e[i] - e[i - 1]) / ld(e[i] - e[l]), ans);
        //cout << l << ' ' << i - 1 << ' ' << i << ' ' << e[l] << ' ' << e[i - 1] << ' ' << e[i] << endl;
        ans = max(ld(e[i] - e[l + 1]) / ld(e[i] - e[l]), ans);
    }
    if (!f) {
        cout << -1 << endl;
        return 0;
    }
    cout << fixed << setprecision(11) << ans << endl;
}
