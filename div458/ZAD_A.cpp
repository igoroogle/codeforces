#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
bool sqt(ll x) {
    if (x < 0) {
        return false;
    }

    for (ll i = 0; i * i <= x; ++i) {
        if (i * i == x) {
            return true;
        }
    }
    return false;
}

int main() {
    ll n, x, ans = -1000010;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        if (!sqt(x)) {
            ans = max(x, ans);
        }
    }

    cout << ans << endl;
}
