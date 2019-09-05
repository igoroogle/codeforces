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
    //cin.tie(NULL);
    ll ans = 0, n, a, b, c;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i; j <= n; ++j) {
            a = i;
            b = j;
            c = a ^ b;
            if ((c <= n) && (c >= b) && (a < b + c) && (b < a + c) && (c < a + b)) {
                ++ans;
                //cout << a << ' ' << b << ' ' << c << endl;
            }
        }
    }
    cout << ans << endl;
}
