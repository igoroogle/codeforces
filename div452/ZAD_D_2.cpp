#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define em emplace_back
#define sqr(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
vector<ll> a;
ll pw[10];
int main() {
    ios_base::sync_with_stdio(0);
    pw[0] = 1;
    for (ll i = 1; i < 10; ++i) {
        pw[i] = pw[i - 1] * ll(10);
    }

    cin >> n;
    if (n < 5) {
        cout << n * (n - 1) / 2 << endl;
        return 0;
    }

    int x;
    while (n > 0) {
        a.pb(n % 10);
        n /= 10;
    }

    reverse(a.begin(), a.end());
    ll kl = 0;
    ll ans = 0, tans = 0;
    bool f;
    if (a[0] < 5) {
        kl = a.size() - 1;
        ans += a[0] * a[0] * pw[kl];
        f = true;
        tans = a[0] * a[0];
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] < 5) {
                f = false;
                break;
            }
            ans += tans * a[i];
            ans += ll(a[i] - 5) * ll(2) * pw[a.size() - i - 1];
        }
        if (f) {
            tans += 2;
        }
        tans *= a[0] * a[0];
        ans += tans;
    } else {
        kl = a.size();
        f = true;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] < 5) {
                f = false;
                break;
            }
            ans += ll(a[i] - 5) * ll(2) * pw[a.size() - i - 1];
        }
        if (f) {
            ans += ll(2);
        }
    }
    cout << ans / ll(2) << endl;
}
