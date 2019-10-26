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

bool comp(pii a, pii b) {
    if (a.x < b.x) {
        return 1;
    } else if (a.x > b.x) {
        return 0;
    } else if (a.y > b.y) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> ar(n);
        forn(i, n) {
            readp(ar[i]);
        }
        sort(all(ar), comp);
        multiset<int> vals;
        ll ans = 0;
        int cur = 0;
        forb (n, i) {
            vals.insert(ar[i].y);
            while (ar[i].x > i + cur) {
                ans += *vals.begin();
                vals.erase(vals.begin());
                ++cur;
            }
        }
        cout << ans << '\n';
    }
}