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
const int LEN = 300010;

int lenval[LEN];
pii a[LEN];
int main() {
    ios_base::sync_with_stdio(0);
    fill(lenval, lenval + LEN, -1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = mp(x, i);
    }

    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n - 1; ++i) {
        cout << 2 * a[i].y + 1 << ' ' << 2 * a[i + 1].y + 1 << '\n';
    }

    for (int i = 0; i < n; ++i) {
        lenval[i] = 2 * a[i].y;
    }

    for (int i = 0; i < n; ++i) {
        cout << lenval[a[i].x + i - 1] + 1 << ' ' << 2 * a[i].y + 2 << '\n';
        if (lenval[a[i].x + i] == -1) {
            lenval[a[i].x + i] = 2 * a[i].y + 1;
        }
    }
}
