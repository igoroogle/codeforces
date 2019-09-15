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
const int RLEN = 50010;

int val[RLEN];
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int vl = s[i] - '0';
        for (int i = 0; i < y; ++i) {
            val[i] += vl;
        }

        for (int i = y; i < RLEN; ++i) {
            if ((i - y) % x == 0) {
                vl ^= 1;
            }
            val[i] += vl;
        }
    }

    int ans = 0;
    for (int i = 0; i < RLEN; ++i) {
        ans = max(ans, val[i]);
    }

    cout << ans << '\n';
}
