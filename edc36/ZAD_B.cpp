#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1E18;
ll a[110];
ll get_ans(ll n, ll pos, ll l, ll r) {
    ll ans = 0;
    if ((l == 1) && (r == n)) {
        return 0;
    }

    if (pos >= l) {
        ans = pos - l + 1;
    } else {
        ans = l - pos + 1;
    }

    if (r != n) {
        ans += r - l + 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, pos, l, r;
    cin >> n >> pos >> l >> r;
    cout << min(get_ans(n, pos, l, r), get_ans(n, n - pos + 1, n - r + 1, n - l + 1)) << endl;
}
