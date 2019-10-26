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
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        vector<bool> use(10);
        int x = i;
        bool f = true;
        while (x > 0) {
            if (use[x % 10]) {
                f = false;
                break;
            }
            use[x % 10] = true;
            x /= 10;
        }

        if (f) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}