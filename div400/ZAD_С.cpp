#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
map<ll, ll> t;
const ll INF = 1E14 + 11;
ll a[100010], st[83];
int main() {
    ll n, k, i, j, x, kl = 0, ans = 0;
    cin >> n >> k;
    if (k == 1) {
        st[0] = 1;
        kl = 1;
    } else if (abs(k) < 2) {
        kl = 2;
        st[0] = 1;
        st[1] = k;
    } else {
        kl = 1;
        st[0] = 1;
        while (abs(st[kl - 1] * k) < INF) {
            st[kl] = st[kl - 1] * k;
            ++kl;
        }
    }

    t[0] = 1;
    for (i = 1; i <= n; ++i) {
        scanf("%I64d", &x);
        a[i] = a[i - 1] + x;
        ++t[a[i]];
    }

    for (i = n; i >= 1; --i) {
        --t[a[i]];
        for (j = 0; j < kl; ++j) {
            ans += t[a[i] - st[j]];
        }
    }

    cout << ans << endl;
}
