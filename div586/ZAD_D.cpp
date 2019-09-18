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

ll b[200010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll st = (ll(1) << ll(60));
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        while (b[i] % st != 0) {
            st >>= ll(1);
        }
    }

    vector<ll> ans;
    for (int i = 0; i < n; ++i) {
        if ((b[i] / st) % 2 == 0) {
            ans.pb(b[i]);
        }
    }

    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}
