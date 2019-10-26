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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, p;
    cin >> n >> p;
    ll k = 1;
    while (n - p * k > ll(0)) {
        ll sum = 0;
        ll cur = n - p * k;
        while (cur > 0) {
            sum += cur & ll(1);
            cur >>= ll(1);
        }

        if ((k >= sum) && (k <= n - p * k)) {
            cout << k << '\n';
            return 0;
        }
        ++k;
    }

    cout << "-1\n";
}