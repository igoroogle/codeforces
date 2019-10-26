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
const int LEN = 1003;
const ll MOD = 1E9 + 7;

int a[LEN][LEN];

void check(int i, int j, int val) {
    if (a[i][j] == 0) {
        a[i][j] = val;
        return;
    }

    if (a[i][j] == val) {
        return;
    }

    cout << "0\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            check(i, j, 1);
        }
        check(i, x, 2);
    }

    for (int i = 0; i < w; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            check(j, i, 1);
        }
        check(x, i, 2);
    }

    ll ans = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0;j < w; ++j) {
            if (a[i][j] == 0) {
                ans = (ans * ll(2)) % MOD;
            }
        }
    }

    cout << ans << '\n';
}