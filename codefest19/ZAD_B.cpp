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
int a[2001];
map<int, int> vl;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++vl[a[i]];
        if (vl[a[i]] == 2) {
            ++cnt;
        }
    }

    if (cnt == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = n;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            --vl[a[j]];
            if (vl[a[j]] == 1) {
                --cnt;
            }

            if (cnt == 0) {
                ans = min(ans, j - i + 1);
            }
        }

        for (int j = i; j < n; ++j) {
            ++vl[a[j]];
            if (vl[a[j]] == 2) {
                ++cnt;
            }
        }
    }


    cout << ans << '\n';
}
