#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
map<ll, ll> vl;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, x, mn = INF, ans = INF;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> x;
        if (x < mn) {
            mn = x;
            ans = INF;
        } else if (x == mn) {
            ans = min(ans, i - vl[x]);
        }
        vl[x] = i;
    }
    cout << ans << endl;
}
