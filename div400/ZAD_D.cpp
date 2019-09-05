#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> a[100010], w[100010], room[100010], td;
bool use[100010];
int r[100010], val[100010];
bool dfs(int v, int zr) {
    if (use[v]) {
        return (val[v] == zr);
    }

    use[v] = 1;
    td.pb(v);
    val[v] = zr;
    bool f = 1;
    for (int i = 0; i < a[v].size(); ++i) {
        if (w[v][i] == 1) {
            if (zr == 0) {
                if (!dfs(a[v][i], 0)) {
                    f = 0;
                }
            } else {
                if (!dfs(a[v][i], 1)) {
                    f = 0;
                }
            }
        } else {
            if (zr == 1) {
                if (!dfs(a[v][i], 0)) {
                    f = 0;
                }
            } else {
                if (!dfs(a[v][i], 1)) {
                    f = 0;
                }
            }
        }
    }

    return f;
}

int main() {
    int n, m, i, j, x, g;
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        scanf("%d", &r[i]);
    }

    for (i = 0; i < m; ++i) {
        scanf("%d", &x);
        for(j = 0; j < x; ++j) {
            scanf("%d", &g);
            --g;
            room[g].pb(i);
        }
    }

    for (i = 0; i < n; ++i) {
        a[room[i][0]].pb(room[i][1]);
        w[room[i][0]].pb(r[i]);
        a[room[i][1]].pb(room[i][0]);
        w[room[i][1]].pb(r[i]);
    }


    for (i = 0; i < m; ++i) {
        if (!use[i]) {
            if (dfs(i, 0)) {
                td.clear();
                continue;
            }

            while (!td.empty()) {
                use[td[td.size() - 1]] = 0;
                td.pop_back();
            }

            if (dfs(i, 1)) {
                td.clear();
                continue;
            }

            cout << "NO\n";
            return 0;
        }
    }


    cout << "YES\n";
}
