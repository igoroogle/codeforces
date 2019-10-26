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
ull a[7003];
ll b[7003];
bool use[7003];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ull mask = 0;
    unordered_map<ll, int> tries;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++tries[a[i]];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (tries[a[i]] < 2) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if ((a[i] | a[j]) == a[i]) {
                use[j] = true;
            }
        }
    }

    ans = 0;
    for (int i = 0; i < n; ++i) {
        if (use[i]) {
            ans += b[i];
        }
    }

    cout << ans << '\n';
}