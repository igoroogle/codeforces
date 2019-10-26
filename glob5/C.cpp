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
pair<pii, pii> a[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = mp(mp(x, y), mp(z, i));
    }
    sort(a, a + n);
    int m = 0;
    int l = 0, r = 0;

    while (l < n) {
        r = l;
        while ((r + 1 < n) && (a[r + 1].x ==  a[l].x)) {
            ++r;
        }

        while (l < r) {
            cout << a[l].y.y + 1 << ' ' << a[l + 1].y.y + 1 << '\n';
            l += 2;
        }

        if (l == r) {
            a[m++] = a[l];
        }
        l = r + 1;
    }

    n = m;
    m = 0;
    l = 0;
    r = 0;
    while (l < n) {
        r = l;
        while ((r + 1 < n) && (a[r + 1].x.x ==  a[l].x.x)) {
            ++r;
        }

        while (l < r) {
            cout << a[l].y.y + 1 << ' ' << a[l + 1].y.y + 1 << '\n';
            l += 2;
        }

        if (l == r) {
            a[m++] = a[l];
        }
        l = r + 1;
    }

    n = m;
    for (int i = 0; i < n; i += 2) {
        cout << a[i].y.y + 1 << ' ' << a[i + 1].y.y + 1 << '\n';
    }
}