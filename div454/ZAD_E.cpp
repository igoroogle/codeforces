#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[10000001], pr[10000001], zn[10000001], vl[24];
const int INF = 1E9;
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = INF;
        pr[i] = -1;
        zn[i] = -1;
    }

    while (m--) {
        cin >> u >> v;
        --u;
        --v;
        vl[u] |= (1 << v);
        vl[v] |= (1 << u);
    }

    for (int i = 0; i < n; ++i) {
        dp[(1 << i)] = 0;
    }
    dp[0] = 0;

    for (int i = 0; i < (1 << n); ++i) {
        if (dp[i] == INF) {
            continue;
        }

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (dp[i | vl[j]] > dp[i] + 1) {
                    dp[i | vl[j]] = dp[i] + 1;
                    zn[i | vl[j]] = j;
                    pr[i | vl[j]] = i;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
    int msk = (1 << n) - 1;
    vector<int> ans;
    while ((msk != -1) && (zn[msk] != -1)) {
        ans.push_back(zn[msk] + 1);
        msk = pr[msk];
    }

    reverse(ans.begin(), ans.end());
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}
