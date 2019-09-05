#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;

ll get(ll n, ll k) {
    ll sum = 0;
    while (n > ll(0)) {
        sum += min(k, n);
        n -= min(k, n);
        n -= n / ll(10);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll  ans = (n + ll(1)) / ll(2);
    ll l = 1, r = ans, m;
    while (l < r) {
        m = (l + r) >> ll(1);
        if (get(n, m) < ans) {
            l = m + ll(1);
        } else {
            r = m;
        }
    }

    cout << l << endl;
}
