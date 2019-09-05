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
ll a[100010], sm[100010], dp1[100010], dp2[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, c;
    cin >> n >> c;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        sm[i] = sm[i - 1] + a[i];
        dp1[i] = a[i];
        dp2[i] = a[i];
    }
    sm[n + 1] = sm[n];

    for (int i = 1; i + c - 1 <= n; i += c) {
        sort(dp1 + i, dp1 + i + c);
        for (int j = i + 1; j < i + c; ++j) {
            dp1[j] = 0;
        }
    }

    for (int i = n; i >= c; i -= c) {
        sort(dp2 + i - c + 1, dp2 + i + 1);
        for (int j = i - c + 2; j <= i; ++j) {
            dp2[j] = 0;
        }
    }

    for (int i = 1; i <= n + 1; ++i) {
        dp1[i] += dp1[i - 1];
        dp2[i] += dp2[i - 1];
    }


    ll ans = sm[n];
    if (n % c == 0) {
        ans -= dp1[n];
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i + n % c - 1 <= n; i += n % c) {
        if ((i - 1) % c) {
            continue;
        }
        ans = min(ans, sm[n] - dp1[i - 1] - (dp2[n + 1] - dp2[i + n % c - 1]));
    }
    cout << ans << endl;
}
