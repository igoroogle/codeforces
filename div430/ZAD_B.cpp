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
    ll r, d, n, x, y, r2, i, ras, ras2, rr, ans = 0;
    cin >> r >> d >> n;
    for (i = 0; i < n; ++i) {
        cin >> x >> y >> r2;
        ras = x * x + y * y;
        ras2 = r - d;
        rr = ras2 + r2;
        if ((r >= r2) && (ras >= rr * rr)  && (ras <= (r - r2) * (r - r2))) {
            ++ans;
        }
    }

    cout << ans << endl;
}
