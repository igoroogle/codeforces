#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
ll a[110];
int main() {
    ll n, m, i, x, ans = 0, l, r;
    cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        scanf("%I64d", &x);
        a[i] = a[i - 1] + x;
    }

    for (i = 0; i < m; ++i) {
        scanf("%I64d%I64d", &l, &r);
        if (a[r] - a[l - 1] > 0)
            ans += a[r] - a[l - 1];
    }

    cout << ans << endl;
}
