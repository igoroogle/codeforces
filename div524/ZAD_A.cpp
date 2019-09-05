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

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ans += ll(2 * n - 1) / k + ll(1);
    ans += ll(5 * n - 1) / k + ll(1);
    ans += ll(8 * n - 1) / k + ll(1);
    cout << ans << '\n';
}
