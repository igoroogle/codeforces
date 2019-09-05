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
vector<ll> a;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, ans = 0, l, r;
    cin >> n;
    if (n == 2) {
        cout << "1\n1 1\n";
        return 0;
    }

    if (n % 2) {
        a.pb(3);
        l = 4;
        r = n;
        if ((n + 1) % 4) {
            ans = 1;
        }
    } else {
        l = 1;
        r = n;
        if (n % 4) {
            ans = 1;
        }
    }

    while (l < r) {
        if (l + 1 < r) {
            a.pb(l);
            a.pb(r);
            l += 2;
            r -= 2;
            continue;
        } else {
            a.pb(l);
            break;
        }
    }

    cout << ans << '\n';
    cout << a.size();
    for (size_t i = 0; i < a.size(); ++i) {
        cout << ' ' << a[i];
    }
    cout << '\n';
}
