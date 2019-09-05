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

ll sum(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans += n % ll(10);
        n /= ll(10);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll ost = n, ans = sum(n);
    ll i = 9;
    while (i <= n) {
        ans = max(ans, sum(i) + sum(n - i));
        i = i * ll(10) + ll(9);
    }

    cout << ans << '\n';
}
