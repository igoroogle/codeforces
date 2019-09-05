#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, l = 0, r = 2E9, sm, mm;
    cin >> n >> m;
    if (m >= n) {
        cout << n << endl;
        return 0;
    }

    n = n - m;
    while (l < r) {
        mm = (l + r) >> ll(1);
        sm = ll(mm + 1) * mm / ll(2);
        if (sm < n) {
            l = mm + ll(1);
        } else {
            r = mm;
        }
    }

    cout << m + l << endl;
}
