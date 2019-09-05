#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> ed[200010];
int x[200010], v[200010], n, val[200010], ans = 0;
void dfs(int v, int p) {
    int i, col1, col2, cur = 1;
    if (p == -1) {
        col1 = 0;
    } else {
        col1 = val[p];
    }

    col2 = val[v];
    for (i = 0; i < ed[v].size(); ++i) {
        if (ed[v][i] != p) {
            while ((cur == col1) || (cur == col2)) {
                ++cur;
            }

            val[ed[v][i]] = cur;
            cur++;
            dfs(ed[v][i], v);
        }
    }

    ans = max(cur - 1, ans);
}

int main() {
    int n, i, j, x, y;
    cin >> n;
    for (i = 0; i < n - 1; ++i) {
        scanf("%d%d", &x, &y);
        --x;
        --y;
        ed[x].pb(y);
        ed[y].pb(x);
    }

    val[0] = 1;
    dfs(0, -1);
    cout << ans << endl;
    for (i = 0; i < n; ++i) {
        printf("%d ", val[i]);
    }
}
