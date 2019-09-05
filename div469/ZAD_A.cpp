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
    ll l, r, a, ans = 0;
    cin >> l >> r >> a;
    for (;;) {
        if ((l > 0) && (r > 0)) {
            ans += ll(2);
            --l;
            --r;
            continue;
        }

        if ((l > 0) && (a > 0)) {
            ans += ll(2);
            --l;
            --a;
            continue;
        }

        if ((r > 0) && (a > 0)) {
            ans += ll(2);
            --r;
            --a;
            continue;
        }

        if (a > ll(1)) {
            ans += ll(2);
            a -= ll(2);
            continue;
        }
        break;
    }
    cout << ans << endl;
}
