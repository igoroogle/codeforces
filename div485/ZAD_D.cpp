#include<bits/stdc++.h>
#define pb push_back
#define em emplace_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9 + 7;

int d[103][100004], a[103];
vector<int> rs[103], ed[100004];
queue<int> q;


int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k, s, ind, u, v;
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; ++i) {
        cin >> ind;
        --ind;
        rs[ind].pb(i);
    }

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    queue<int> q;
    for (int i = 0; i < k; ++i) {

        for (int j = 0; j < n; ++j) {
            d[i][j] = INF;
        }

        for (auto cur : rs[i]) {
            q.push(cur);
            d[i][cur] = 0;
        }

        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (auto u : ed[v]) {
                if (d[i][u] != INF) {
                    continue;
                }
                d[i][u] = d[i][v] + 1;
                q.push(u);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            a[j] = d[j][i];
        }

        sort (a, a + k);
        int ans = 0;
        for (int j = 0; j < s; ++j) {
            ans += a[j];
        }

        cout << ans << ' ';
    }

}
