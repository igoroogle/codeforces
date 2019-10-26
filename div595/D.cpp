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

const int LEN = 200010;
vector<pii> a[LEN];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        a[l].em(r, i);
    }

    set<pii> vals;
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < LEN; ++i) {
        while ((!vals.empty()) && (vals.begin()->x < i)) {
            vals.erase(vals.begin());
            --cnt;
        }

        for (auto cur : a[i]) {
            vals.insert(cur);
            ++cnt;
        }

        while (cnt > k) {
            ans.pb(vals.rbegin()->y);
            vals.erase(*(vals.rbegin()));
            --cnt;
        }
    }

    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur + 1 << ' ';
    }
}