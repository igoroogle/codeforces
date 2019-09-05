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

const int INF = 2E9 + 3;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int dh = -INF, dm = -INF;
        for (int i = 0; i < n; ++i) {
            int d, h;
            cin >> d >> h;
            dh = max(dh, d - h);
            dm = max(d, dm);
        }

        if (x <= dm) {
            cout << "1\n";
            continue;
        }

        if (dh <= 0) {
            cout << "-1\n";
            continue;
        }

        cout << (x - dm - 1) / dh + 2 << '\n';
    }
}
