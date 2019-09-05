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
const ll INF = 2E18 + 3;
ll a[55], b[55];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    ll ans = INF;
    for (int k = 0; k < n; ++k) {
        ll toans = -INF;
        for (int i = 0; i < n; ++i) {
            if (i != k) {
                for (int j = 0; j < m; ++j) {
                    toans = max(a[i] * b[j], toans);
                }
            }
        }
        ans = min(toans, ans);
    }
    cout << ans << endl;
}
