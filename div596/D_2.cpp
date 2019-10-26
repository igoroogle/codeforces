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
        ans *= ans;
        if (n & ll(1)) {
            ans *= a;
        }

        if (ans > INF) {
            ans = INF;
        }

        return ans;
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
        ll ans = 1, bans = 1;
        while (i * i <= x) {
            if (x % i == 0) {
                ll powval = 0;
                while (x % i == 0) {
                    x /= i;
                    ++powval;
                }
                powval %= k;
                ans *= binpow(ll(i), powval);
                if (powval > ll(0)) {
                    bans *= binpow(ll(i), k - powval);
                }

                ans = min(ans, INF);
                bans = min(bans, INF);
            }
            ++i;
        }

        if (x > 0) {
            ans *= x;
            bans *= binpow(x, k - ll(1));
            ans = min(ans, INF);
            bans = min(bans, INF);
        }


        if (bans != INF) {
            toans += vals[bans];
        }

        if (ans < INF) {
            ++vals[ans];
        }
    }

    cout << toans << '\n';
}