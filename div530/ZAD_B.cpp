#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    ll n, ans;
    cin >> n;
    ans = n + ll(1);
    for (ll i = 1; i * i <= n; ++i) {
        ll m = (n - ll(1)) / i + ll(1);
            ans = min(ans, i + m);
    }

    cout << ans << '\n';
    return 0;
}
