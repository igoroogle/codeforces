#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
map<ll, bool> t;
int main() {
    ios_base::sync_with_stdio(0);
    ll b, q, l, m, i, x, ans = 0;
    cin >> b >> q >> l >> m;
    while (m--) {
        cin >> x;
        t[x] = 1;
    }

    if ((b == ll(0)) || (abs(q) <= ll(1))) {
        for (i = 0; i < 100; ++i) {
            if (abs(b) > l) {
                cout << ans << endl;
                return 0;
            }

            if (!t[b]) {
                ++ans;
            }

            b *= q;
        }

        if (ans < ll(2)) {
            cout << ans << endl;
        }
        else {
            cout << "inf\n";
        }
        return 0;
    }

    while (abs(b) <= l) {
        if (!t[b]) {
            ++ans;
        }
        b *= q;
    }

    cout << ans << endl;
}
