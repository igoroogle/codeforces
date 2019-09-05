#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
ll n, k;
ll dp[6][200002], dd[6][200002], ans = 0;
vector<ll> ed[200002];
void dfs(ll v, ll p) {
    ll i, j, t, v1, v2, vl1, vl2, an, fir, sec;
    dd[0][v] = 1;
    for (i = 0; i < ed[v].size(); ++i) {
        if (ed[v][i] != p) {
            dfs(ed[v][i], v);
            for (j = 0; j < k; ++j) {
                for (t = 0; t < k; ++t) {
                    v1 = dd[j][v];
                    v2 = dd[t][ed[v][i]];
                    vl1 = dp[j][v];
                    vl2 = dp[t][ed[v][i]];
                    if (t == k - 1) {
                        vl2 += v2;
                    }

                    an = 0;
                    an += vl1 * v2;
                    an += vl2 * v1;
                    fir = j;
                    sec = (t + 1) % k;
                    if (fir + sec > 0) {
                        an += v1 * v2;
                    }

                    if (fir + sec > k) {
                        an += v1 * v2;
                    }

                    ans += an;
                }
            }

            for (j = 0; j < k; ++j) {
                dp[(j + 1) % k][v] += dp[j][ed[v][i]];
                if (j == k - 1) {
                    dp[(j + 1) % k][v] += dd[j][ed[v][i]];
                }

                dd[(j + 1) % k][v] += dd[j][ed[v][i]];
            }
        }
    }
}

int main() {
    cin >> n >> k;
    ll i, x, y;
    for (i = 0; i < n - 1; ++i) {
        scanf("%I64d%I64d", &x, &y);
        --x;
        --y;
        ed[x].pb(y);
        ed[y].pb(x);
    }

    dfs(0, -1);
    cout << ans << endl;
}
