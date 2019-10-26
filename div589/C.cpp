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

const ll MOD = 1E9 + 7;

ll binpow (ll a, ll n) {
    ll res = 1;
    while (n > ll(0)) {
        if (n & ll(1))
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= ll(1);
    }
    return res;
}


void add_ans(ll& ans, ll n, ll x) {
    ll st = x;
    ll sqn = ll(sqrt(ld(n))) + ll(2);
    ll sqx = max(ll(sqrt(ld(x))), ll(1));
    ll sqst = 1;
    for(;;) {
        //cout << x << ' ' << st << ' ' << binpow(x, n / st) << endl;
        ans = (ans * binpow(x, n / st)) % MOD;
        sqst = max(ll(1), ll(sqrt(ld(st))));
        if (sqx * sqst > sqn) {
            break;
        }
        st *= x;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    ll x, n;
    cin >> x >> n;
    ll ans = 1;
    ll i = 2;
    while (i * i <= x) {
        if (x % i == ll(0)) {
            add_ans(ans, n, i);
            while (x % i == ll(0)) {
                x /= i;
            }
        }
        ++i;
    }

    if (x > ll(1)) {
        add_ans(ans, n, x);
    }

    cout << ans << '\n';
}