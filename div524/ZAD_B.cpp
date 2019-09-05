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

ll get(ll r) {
    ll rr = (r + ll(1)) / ll(2) ;
    if (r % 2) {
        return -rr;
    } else {
        return rr;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << '\n';
    }
}
