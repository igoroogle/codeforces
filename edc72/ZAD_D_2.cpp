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

vector <int> g[LEN], gr[LEN], tp[LEN];
vector<pii> rb;
vector<bool> used, use;
vector<int> order, component;
int col[LEN];

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
	cin >> n >> m;
	rb.resize(m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
        rb[i] = mp(u, v);
		g[u].pb(v);
		tp[u].pb(i);
		gr[v].pb(u);
	}

	used.assign(n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
	int k = 1;
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
			use.assign(n, false);
			for (auto cur : component) {
                use[cur] = true;
			}

			int cnt = 0;
			for (int u = 0; u < n; ++u) {
                if (!use[u]) {
                    continue;
                }
                for (int j = 0; j < g[u].size(); ++j) {
                    int v = g[u][j];
                    if (use[v]) {
                        ++cnt;
                        col[tp[u][j]] = cnt;
                    } else {
                        col[tp[u][j]] = 1;
                    }
                }
			}
			k = max(cnt, k);
			component.clear();
		}
	}

	cout << k << '\n';
	for (int i = 0; i < m; ++i) {
        cout << col[i] << ' ';
	}
}
