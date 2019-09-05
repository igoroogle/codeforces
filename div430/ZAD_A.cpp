#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll l, r, x, y, k, i;
    cin >> l >> r >> x >> y >> k;
    for (i = x; i <= y; ++i) {
        if ((k * i >= l) && (k * i <= r)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
