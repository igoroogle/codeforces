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

pair<ll, int> a[200010];
ll difL[200010], difR[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n <= 3) {
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] = mp(x, i);
    }

    sort(a, a + n);
    difL[1] = a[1].x - a[0].x;

    for (int i = 2; i < n; ++i) {
        if (a[i].x - a[i - 1].x == difL[i - 1]) {
            difL[i] = difL[i - 1];
        } else {
            difL[i] = -1;
        }
    }

    difR[n - 2] = a[n - 1].x - a[n - 2].x;
    for (int i = n - 3; i >= 0; --i) {
        if (a[i + 1].x - a[i].x == difR[i + 1]) {
            difR[i] = difR[i + 1];
        } else {
            difR[i] = -1;
        }
    }

    if (difR[1] != -1) {
        cout << a[0].y + 1 << '\n';
        return 0;
    }

    if (difR[2] == a[2].x - a[0].x) {
        cout << a[1].y + 1 << '\n';
        return 0;
    }

    if (difL[n - 2] != -1) {
        cout << a[n - 1].y + 1 << '\n';
        return 0;
    }

    if (difL[n - 3] == a[n - 1].x - a[n - 3].x) {
        cout << a[n - 2].y + 1 << '\n';
        return 0;
    }

    for (int i = 2; i < n - 2; ++i) {
        if ((difR[i + 1] == difL[i - 1]) && (difL[i - 1] == a[i + 1].x - a[i - 1].x)) {
            cout << a[i].y + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}