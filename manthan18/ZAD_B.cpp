#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i <= n / 2; ++i) {
        if (a[i] > s) {
            ans += a[i] - s;
            a[i] = s;
        }
    }

    for (int i = n / 2; i < n; ++i) {
        if (a[i] < s) {
            ans += s - a[i];
            a[i] = s;
        }
    }

    cout << ans << '\n';
}
