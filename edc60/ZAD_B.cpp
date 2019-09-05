#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int a[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    ll mx = a[n - 1];
    ll px = a[n - 2];
    ll ans = ll(m) / ll(k + 1) * (mx * ll(k) + px) + ll(m) % ll(k + 1) * mx;
    cout << ans << '\n';
}
