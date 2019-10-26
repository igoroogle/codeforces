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

bool use[100010];

int main() {
    ios_base::sync_with_stdio(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll y = 0, val = p;
    val = val % w;
    use[0] = true;
    while (!use[val]) {
        use[val] = true;
        ++y;
        val = (val + w - d) % w;
    }

    if (val != ll(0)) {
        cout << "-1\n";
    } else {
        ll x = (p - y * d) / w;
        ll z = n - x - y;
        if (z < ll(0)) {
            cout << "-1\n";
            return 0;
        }
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}