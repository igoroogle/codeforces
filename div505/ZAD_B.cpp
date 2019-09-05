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
const ll DL = 44723;

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vector<ll> vals;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll vl = 0, a, b;
    while (n--) {
        cin >> a >> b;
        vals.pb(a);
        vals.pb(b);
        vl = gcd(vl, lcm(a, b));
    }

    if (vl == 1) {
        cout << -1 << '\n';
        return 0;
    }

    for (ll i = 2; i <= DL; ++i) {
        if (vl % i == 0) {
            cout << i << '\n';
            return 0;
        }
    }

    sort(vals.begin(), vals.end());
    for (auto cur : vals) {
        if (vl % cur == 0) {
            cout << cur << '\n';
            return 0;
        }
    }

    cout << vl << endl;
}
