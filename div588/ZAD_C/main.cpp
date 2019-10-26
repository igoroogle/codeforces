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
int ans = 0, n;
vector<int> ed[8];
bool use[7][7];
int col[8];

void rec(int cur) {
    if (cur < n) {
        for (int i = 0; i < 6; ++i) {
            col[cur] = i;
            rec(cur + 1);
        }
        return;
    }

    /*for (int i = 0; i < n; ++i) {
        cout << col[i] << ' ';
    }
    cout << endl;*/

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            use[i][j] = false;
        }
    }

    int vans = 0;
    for (int u = 0; u < n; ++u) {
        for (auto v : ed[u]) {
            use[col[u]][col[v]] = true;
            use[col[v]][col[u]] = true;
        }
    }

    vans = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = i; j < 6; ++j) {
            if (use[i][j]) {
                ++vans;
            }
        }
    }

    ans = max(ans, vans);
}

int main() {
    ios_base::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
    }
    rec(0);
    cout << ans << '\n';
}