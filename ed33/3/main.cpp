#include <algorithm>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>

#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> g[100010];
ll c[100010];
bool use[100010];
ll dfs(int v) {
    use[v] = true;
    ll ans = c[v];
    for (auto u : g[v]) {
        if (!use[u]) {
            ans = min(dfs(u), ans);
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            ans += dfs(i);
        }
    }

    cout << ans << endl;
    return 0;
}
