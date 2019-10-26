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
typedef pair<ll, ll> pll;

const ll MAXLEN = 1E9 + 3;

int check(const vector<pll>& ar, ll k, ll s) {
    ll a = 0, b = 0, c = 0;
    ll smin = 0, smax = 0;
    int n = ar.size();
    for (auto cur : ar) {
        if (cur.y < k) {
            ++a;
            smin += cur.x;
        } else if (cur.x > k) {
            ++b;
            smax += cur.x;
        } else {
            ++c;
        }
    }
    ll m = n / 2;

    if (a > m) {
        return false;
    }

    if (b > m) {
        return true;
    }

    for (auto cur : ar) {
        if (a == m) {
            break;
        }

        if ((cur.x <= k) && (cur.y >= k)) {
            ++a;
            --c;
            smin += cur.x;
        }
    }

    if (c < 0) {
        for(;;);
    }

    return (smin + smax + c * k <= s);
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll s;
        cin >> n >> s;
        vector<pll> ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i].x >> ar[i].y;
        }
        sort(ar.begin(), ar.end());
        ll l = 1, r = MAXLEN;
        while (l < r) {
            ll m = (r + l) >> ll(1);
            if (check(ar, m, s)) {
                l = m + ll(1);
            } else {
                r = m;
            }
        }
        cout << l - ll(1) << '\n';
    }
}