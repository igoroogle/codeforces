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
ll get_sum(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    int ans = 0, k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        ++ans;
        while (get_sum(ans) != 10) {
            ++ans;
        }
    }
    cout << ans << endl;
}
