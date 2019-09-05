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
const int DL = 2010;
const ll INF = 1E18;
ll d1[DL], d2[DL], a[DL], b[DL];

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    cin >> x;

    for (int i = 0; i < DL; ++i) {
        d1[i] = INF;
        d2[i] = INF;
    }


    for (int i = 0; i < n; ++i) {
        ll ans = 0;
        for (int j = i; j < n; ++j) {
            ans += a[j];
            d1[j - i + 1] = min(ans, d1[j - i + 1]);
        }
    }

    for (int i = 0; i < m; ++i) {
        ll ans = 0;
        for (int j = i; j < m; ++j) {
            ans += b[j];
            d2[j - i + 1] = min(ans, d2[j - i + 1]);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (d1[i] * d2[j] <= x) {
                ans = max(ll(i * j), ans);
            }
        }
    }
    cout << ans << '\n';
}
