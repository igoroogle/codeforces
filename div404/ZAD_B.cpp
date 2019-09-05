#include<bits/stdc++.h>
using namespace std;
const int INF = 2E9;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    int i, n, l1 = -INF, r1 = INF, l2 = -INF, r2 = INF, ans = 0, l, r;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> l >> r;
        l1 = max(l1, l);
        r1 = min(r1, r);
    }

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> l >> r;
        l2 = max(l2, l);
        r2 = min(r2, r);
    }

    if (r1 < l2) {
        ans = max(ans, l2 - r1);
    }

    if (r2 < l1) {
        ans = max(ans, l1 - r2);
    }

    cout << ans << endl;
}
