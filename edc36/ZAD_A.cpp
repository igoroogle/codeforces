#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1E18;
ll a[110];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, x, ans = INF;
    cin >> n >> k;
    while (n--) {
        cin >> x;
        if (k % x == 0) {
            ans = min(ans, k / x);
        }
    }
    cout << ans << endl;
}
