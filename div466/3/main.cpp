#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll a[2010];

int main() {
    ios_base::sync_with_stdio(0);
    ll n, x, ans = 0, sm = 0;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        if (x == 1) {
            ++sm;
        }
        ans = gcd(x, ans);
        a[i] = x;
    }

    ll mn;
    if (ans != 1) {
        cout << -1 << endl;
    } else if (sm > 0) {
        cout << n - sm << endl;
    } else {
        mn = 3010;
        for (ll i = 0; i < n; ++i) {
            ans = a[i];
            for (ll j = i + 1; j < n; ++j) {
                ans = gcd(ans, a[j]);
                if (ans == 1) {
                    mn = min(mn, j - i);
                    break;
                }
            }
        }
        cout << mn + n - 1 << endl;
    }
    return 0;
}