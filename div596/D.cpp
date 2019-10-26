#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>
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
#define sqr(x) ((x) * (x))
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forb(n, i) for (int i = n - 1; i >= 0; --i)
#define readp(v) cin >> (v).x >> (v).y

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld PI = 3.141592653589793116;
const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
const int LEN = 8;
const ll INF = 1E5 + 3;

map<ll, ll> vals;
ll binpow (ll a, ll n) {
    if (n == 0) {
        return ll(1);
    } else if (n == 1) {
        return a;
    } else {
        ll ans = binpow(a, n >> ll(1));
        ll ans = ans * ans;
        if (n & ll(1)) {

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    ll toans = 0;

    while(n--) {
        int x;
        cin >> x;
        int i = 2;
        while (i * i <= x) {
            if (x % i == 0) {
                a.pb(x);
                kol.pb(0);
                while (x % i == 0) {
                    x /= i;
                    ++kol.back();
                }
            }
            ++i;
        }

        if (x > 0) {
            a.pb(x);
            kol.pb(1);
        }

        vector<vector<int>> b(a.size());
        forn (i, a.size()) {
            b[i].resize(int(primes.back()) + 1);
            b[i][0] = 1;
            for (int j = 1; j <= int(primes.back()); ++j) {
                auto cur  = ll(b[i][j - 1]) * ll(a[i]);
                if (cur > INF) {
                    cur = INF;
                }
                b[i][j] = cur;
            }
        }

        forn (i, LEN) {
            int ans = 1, vans = 1;
            forn(j, a.size()) {
                int vt = kol[j] % primes[i];
                cout << "vt " << vt << ' ' << i << ' ' << j << ' ' << a[j] << endl;
                auto cur = ll(ans) * ll(b[j][vt]);
                cout << " fb  " << ll(b[j][vt]) << endl;
                if (cur < INF) {
                    ans = cur;
                } else {
                    ans = INF;
                }

                if (vt > 0) {
                    vt = primes[i] - vt;
                }

                cout << "vts " << vt << ' ' << i << ' ' << j << ' ' << a[j] << endl;

                cur = ll(vans) * ll(b[j][primes[i] - vt]);
                cout << " b  " << ll(b[j][primes[i] - vt]) << endl;
                if (cur < INF) {
                    vans = cur;
                } else {
                    vans = INF;
                }
            }

            if (vans < INF) {
                toans += vals[i][vans];
            }

            if (ans < INF) {
                ++vals[i][ans];
            }
            cout << " ans vans " << i << ' ' << ans << ' ' << vans << endl;
        }
        //cout << toans << endl;
    }

    cout << toans << '\n';
}