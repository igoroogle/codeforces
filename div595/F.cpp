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

const int LEN = 205;

ll dp[LEN][LEN], sm[LEN][LEN], a[LEN];
vector<int> ed[LEN];

void dfs(int v, int p, int k) {
    for (auto u : ed[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v, k);

        for (int i = 0; i <= k + 1; ++i) {
            sm[v][i] += dp[u][i];
        }
    }

    dp[v][0] = sm[v][k] + a[v];

    for (int i = 1; i <= k + 1; ++i) {
        for (auto u : ed[v]) {
            if (u == p) {
                continue;
            }

            dp[v][i] = max(dp[v][i], dp[u][i - 1] + sm[v][k - i] - dp[u][k - i]);
        }
    }

    for (int i = k; i >= 0; --i) {
        dp[v][i] = max(dp[v][i], dp[v][i + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    dfs(0, -1, k);
    cout << dp[0][0] << '\n';

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            cout << i << ' ' << j << ' ' <<  dp[i][j] << endl;
        }
    }
}