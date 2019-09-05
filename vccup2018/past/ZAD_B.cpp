#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
ll t[100010], v[100010], ans[100010], vl[100010], tt[100010], vv[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, l, r, m;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
        vv[i] = v[i] + vv[i - 1];
    }

    for (ll i = 1; i <= n; ++i) {
        cin >> t[i];
        tt[i] = t[i] + tt[i - 1];
    }

    tt[n + 1] = ll(1E9 + 3) + t[n];
    for (ll i = 1; i <= n; ++i) {
        l = i;
        r = n + 1;
        while (l < r) {
            m = (l + r) >> ll(1);
            if (tt[m] - tt[i - 1] < v[i]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans[l] += v[i] - tt[l - 1] + tt[i - 1];
        ++vl[l];
    }

    ll an = 0;
    for (ll i = 1; i <= n; ++i) {
        an += vl[i];
        cout << (i - an) * t[i] + ans[i] << ' ';
    }
}
