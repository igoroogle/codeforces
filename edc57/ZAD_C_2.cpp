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
ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll ang;
        cin >> ang;
        for (ll n = 1; n <= 180; ++n) {
            bool f = false;
            for (ll k = 1; k <= 180; ++k) {
                if (((k * ll(180)) % n == 0) && (ll(180) * k / n == ang)) {
                    f = true;
                    break;
                }
            }
            if (f) {
                cout << n << '\n';
                break;
            }
        }
    }
}
