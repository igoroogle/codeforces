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
        vector<char> odd, even;
        string s;
        cin >> s;
        for (auto cur : s) {
            if (cur % 2) {
                odd.pb(cur);
            } else {
                even.pb(cur);
            }
        }
        vector<char> ans(s.length());
        merge(odd.begin(), odd.end(), even.begin(), even.end(), ans.begin());
        for (auto cur : ans) {
            cout << cur;
        }
        cout << '\n';
    }
}