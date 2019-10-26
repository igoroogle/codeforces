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
        vector<bool> an(26);
        string s;
        cin >> s;
        s.push_back(' ');
        int curVal = 1;
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++curVal;
            } else {
                if (curVal % 2) {
                    an[s[i - 1] - 'a'] = true;
                }
                curVal = 1;
            }
        }

            for (int i = 0; i < 26; ++i) {
                if (an[i]) {
                    cout << char('a' + i);
                }
            }
            cout << '\n';
    }
}