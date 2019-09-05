#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[53][53];
int main() {
    ios_base::sync_with_stdio(0);
    ll m, b, i, ans = 0, x, y, to;
    cin >> m >> b;
    i = 0;
    for(;;) {
        x = i;
        if (x > 0) {
            y = b - ll((x - ll(1)) / m + ll(1));
        } else {
            y = b;
        }

        if (y < 0) {
            break;
        }

        to = (x + ll(1)) * x / ll(2) * ll(y + 1) + (y + ll(1)) * y / ll(2) * ll(x + 1);
        ans = max(ans, to);
        ++i;
    }

    cout << ans << endl;
    return 0;
}
