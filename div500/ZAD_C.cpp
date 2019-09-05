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
const ll INF = 2E18;
ll a[300010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    sort(a, a + (n * 2));
    ll ans = INF;
    for (int i = n - 1; i < n * 2 - 1; ++i) {
        ans = min(ans, (a[i] - a[0]) * (a[n * 2 - 1] - a[n]));
    }

    for (int i = 0; i < n; ++i) {
        ans = min(ans, (a[n + n - 1] - a[0]) * (a[i + n - 1] - a[i]));
    }

    cout << ans << endl;
}
