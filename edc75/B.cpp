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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int zer = 0, ed = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            a[i] = s.length();
            for (auto cur : s) {
                if (cur == '0') {
                    ++zer;
                } else {
                    ++ed;
                }
            }
        }

        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cur = a[i] / 2;
            if (zer / 2 + ed / 2 >= cur) {
                ++ans;
                while (cur > 0) {
                    --cur;
                    if (zer >= 2) {
                        zer -= 2;
                    } else {
                        ed -= 2;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}