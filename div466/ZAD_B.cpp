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
    ll n, k, a, b;
    ll ans = 0;
    cin >> n >> k >> a >> b;
    if (k == ll(1)) {
        cout << (n - ll(1)) * a << endl;
        return 0;
    }

    while (n > ll(1)) {
        //cout << n << ' ' << ans << endl;
        if (n % k == ll(0)) {
            if (b <= a * (n - n / k)) {
                n /= k;
                ans += b;
                continue;
            } else {
                ans += a * (n - n / k);
                n /= k;
                continue;
            }
        }

        if (n > k)
        {
            ans += (n % k) * a;
            n -= n % k;
        } else {
            ans += (n - ll(1)) * a;
            n = ll(1);
        }
    }
    cout << ans << endl;
}
