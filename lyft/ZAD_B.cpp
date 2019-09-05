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

ll prime(ll n) {
    if (n == 1) {
        return false;
    }

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll a, b;
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if ((a - b == ll(1)) && (prime(a + b))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
