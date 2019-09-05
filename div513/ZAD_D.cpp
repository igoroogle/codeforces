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
const int DL = 2010;
const ll INF = 1E18;
ll lf[100010], rf[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> lf[i] >> rf[i];
    }
    sort(lf, lf + n);
    sort(rf, rf + n);
    ll ans = n;
    for (int i = 0; i < n; ++i) {
        ans += max(lf[i], rf[i]);
    }
    cout << ans << '\n';
}
