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
        ll ans = st - in + exp;
        if (ans <= ll(0)) {
            cout << "0\n";
            continue;
        }
        ans = (ans + ll(1)) / ll(2) - ll(1);
        ans = min(ans, exp) + ll(1);
        cout << ans << '\n';
    }
}
