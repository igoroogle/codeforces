#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == ll(0)) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != ll(0))
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= ll(-1);
    if (b < 0)   y0 *= ll(-1);
    return true;
}

ll get_ans(ll x0, ll y0, ll u, ll v, ll n) {
    ll kmax = 0;
    if (v > ll(0)) {
        kmax = y0 / v;
    }
    //cout << kmax << endl;

    ll av = x0 + y0 - n;
    ll bv = v - u;
    if ((av <= ll(0)) && (bv <= ll(0))) {
        av = -av;
        bv = -bv;
    }

    ll ans = 0;
    if ((av >= ll(0)) && (bv >= ll(0))) {
        ans = (av - ll(1)) / bv + ll(1);
    } else {
        return ll(-1);
    }

    if (ans > kmax) {
        return ll(-1);
    }

    //cout << kmax << ' ' << ans << '\n';
    return kmax;
}


int main() {
    ios_base::sync_with_stdio(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll x0, y0, g;
    bool f = find_any_solution(w, d, p, x0, y0, g);

    if (!f) {
        cout << "-1\n";
        return 0;
    }

    ll u = d / g;
    ll v = w / g;
    //cout << "smth\n";
    ll k = get_ans(x0, y0, u, v, n);
    ll x, y, z;
    //cout << "smth\n";
    if (k >= ll(0)) {
        x = x0 + k * u;
        y = y0 - k * v;
    } else {
        k = get_ans(y0, x0, v, u, n);
        if (k < ll(0)) {
            cout << "-1\n";
            return 0;
        }
        //cout << k << endl;
        x = x0 - k * u;
        y = y0 + k * v;
    }

    z = n - x - y;
    if (z < ll(0)) {
        cout << "-1\n";
        return 0;
    }
    cout << x << ' ' << y << ' ' << z << '\n';

}