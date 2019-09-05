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

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    if (n - k < l) {
        cout << -1 << "\n";
        return 0;
    }

    ll ans = (k + l - ll(1)) / m + ll(1);
    if ((ans * m >= k + l) && (ans * m <= n)) {
        cout << ans << '\n';
    } else {
        cout << -1 << endl;
    }
}
