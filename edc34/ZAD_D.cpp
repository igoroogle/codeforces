#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long double ll;
typedef long double ld;
ll a[200010];
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    map<ll, ll> vl;
    ll n, i, ans = 0, sum = 0, tsum, kl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        tsum = sum;
        kl = n - i - 1;
        kl -= vl[a[i] - ll(1)];
        kl -= vl[a[i]];
        kl -= vl[a[i] + ll(1)];
        tsum -= vl[a[i] - ll(1)] * (a[i] - ll(1));
        tsum -= vl[a[i]] * a[i];
        tsum -= vl[a[i] + ll(1)] * (a[i] + ll(1));
        ++vl[a[i]];
        sum += a[i];
        ans += tsum - kl * a[i];
    }
    cout << fixed << setprecision(0) << ans << endl;
}
