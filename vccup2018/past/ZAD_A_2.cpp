#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
ll x1[1000100];
bool pr[1000100];
ll mn = 1E9;
void checks(ll n, ll x) {
    if (n <= x) {
        return;
    }
    mn = min(mn, n - x + ll(1));
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (ll i = 2; i <= n; ++i) {
        for (ll j = i + i; j <= n; j += i) {
            pr[j] = true;
        }
    }

    for (ll i = 1; i <= n; ++i) {
        if ((!pr[i]) && (n % i == ll(0))) {
            checks(n, i);
        }
    }

    mn = max(mn, ll(3));
    ll ans = 1E9;



    //cout << mn << " mn\n";
    for (ll i = 2; i <= n; ++i) {
        if (pr[i]) {
            continue;
        }
        for (int j = i + i; j <= n; j += i) {
            if ((j >= mn) && (ans > j - i + ll(1))) {
                //cout << j << ' ' << i << endl;
                ans = min(ans, j - i + ll(1));
                //cout << ans << endl;
            }
        }
    }
    ans = max(ans, ll(3));
    cout << ans << endl;
}
