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
bool check(ll i, ll p, ll x, ll y) {
    if ((x > p) || (x < ll(2))) {
        return false;
    }

    if (i / x <= y / x) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll p, y;
    cin >> p >> y;
    bool f;
    for (ll i = y; i > p; --i) {
        f = true;
        for (ll j = 2; j * j <= i; ++j) {
            if ((i % j == 0) && (check(i, p, j, y) || check(i, p, i / j, y))) {
                f = false;
                break;
            }
        }

        if (f) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
