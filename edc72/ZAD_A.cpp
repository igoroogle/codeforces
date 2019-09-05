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

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll st, in, exp;
        cin >> st >> in >> exp;
        if (in >= st) {
            exp -= in - st + ll(1);
            st = in + ll(1);
        }

        if (exp < 0) {
            cout << "0\n";
            continue;
        }

        ll diff = st - in - ll(1);
        ll ans = min(diff + ll(1), exp);
        exp -= diff;
        in += diff;
        if (exp <= 0) {
            cout << ans << '\n';
            continue;
        }
        ans += (exp - ll(1)) / ll(2) + ll(1);
        cout << ans << '\n';
    }
}
