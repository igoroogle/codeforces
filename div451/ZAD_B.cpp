#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, a, b;
    cin >> n >> a >> b;
    for (ll i = 0; i * a <= n; ++i) {
        if ((n - i * a) % b == ll(0)) {
            cout << "YES\n";
            cout << i << ' ' << (n - i * a) / b << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}
