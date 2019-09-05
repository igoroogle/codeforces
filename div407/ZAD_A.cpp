#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, ans = 0, x;
    cin >> n >> k;
    while (n--) {
        cin >> x;
        ans += ll(x - 1) / k + ll(1);
    }

    ans = ll(ans - 1) / ll(2) + 1;
    cout << ans << endl;
}
