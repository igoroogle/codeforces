#include<iostream>
#include<iomanip>
#include<utility>
#include<cmath>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll an[100010];

ll pw[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        pw[i] = (pw[i - 1] * ll(2)) % MOD;
    }

    char c;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        an[i] = an[i - 1];
        if (c == '1') {
            ++an[i];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        ll vt = an[r] - an[l - 1];
        ll ans = (pw[vt] + MOD - 1) % MOD;
        vt = r - l + 1 - vt;
        if (vt > 0) {
            ans = (ans + ans * ((pw[vt] + MOD - 1) % MOD)) % MOD;
        }
        cout << ans << '\n';
    }
}