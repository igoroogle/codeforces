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

const ll LN = 513;

ll b[200010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll st = (ll(1) << ll(60));
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll ans = 1, vans = 0;
    for (ll i = 1; i < LN; ++i) {
        ll curans = 0;
        for (int j = 0; j < n; ++j) {
            if (b[j] < i) {
                continue;
            }
            if ((ll(b[j] - 1) / i + ll(1)) & ll(1)) {
                ++curans;
            }
        }
        if (curans > vans) {
            vans = curans;
            ans = i;
        }
    }

    vector<ll> ansv;
    for (int i = 0; i < n; ++i) {
        if (b[i] < ans) {
            ansv.pb(b[i]);
            continue;
        }

        if ((ll(b[i] - 1) / ans + ll(1)) % ll(2) == ll(0)) {
            ansv.pb(b[i]);
        }
    }

    cout << ansv.size() << '\n';
    for (auto cur : ansv) {
        cout << cur << ' ';
    }
}
