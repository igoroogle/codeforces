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
const int LEN = 5010;

vector<pii> g[LEN];
int col[LEN], ans[LEN];
int k = 1;

void dfs (int v) {
	col[v] = 1;
	for (auto cur : g[v]) {
        int u = cur.x;
        ans[cur.y] = 1;
        if (col[u] == 1) {
            ans[cur.y] = 2;
            k = 2;
        } else if (col[u] == 0) {
            dfs(u);
        }
	}
	col[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
        g[u].em(v, i);
	}

	for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            dfs(i);
        }
	}

	cout << k << '\n';
	for (int i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
	}
}
