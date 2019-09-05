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

const int RLEN = 18;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> zers(n + 1);
        zers[0] = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                zers[i + 1] = i;
            } else {
                zers[i + 1] = zers[i];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                continue;
            }

            int cur = 0;
            for (int j = i; j < min(i + RLEN, n); ++j) {
                cur <<= 1;
                cur += s[j] - '0';
                //cout << i << ' ' << j << ' ' << cur << endl;
                int lenmin = j - i + 1;
                int lenmax = i - zers[i] - 1 + lenmin;
                if ((cur >= lenmin) && (cur <= lenmax)) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}
