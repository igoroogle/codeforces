#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    ll sm = 0;
    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(a[i], mx);
        sm += a[i];
    }

    sort(a, a + n + 1);
    ll cur = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > cur) {
            ++ans;
            ++cur;
            continue;
        } else {
            ++ans;
        }
    }

    ans += mx - cur;
    cout << sm - ans << '\n';
}
