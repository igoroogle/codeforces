#include<bits/stdc++.h>
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

vector<int> ed[100010];
int par[100010], cnt[100010];
bool use[100010];

void dfs(int v) {
    for (auto u : ed[v]) {
        dfs(u);
    }

    use[v] = true;
    if (cnt[v] == 0) {
        use[v] = false;
        return;
    }

    for (auto u : ed[v]) {
        if (!cnt[u]) {
            use[v] = false;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int root = -1;
    for (int i = 0; i < n; ++i) {
        int p, c;
        cin >> p  >> c;
        if (p != -1) {
            --p;
        } else {
            root = p;
        }

        par[i] = p;
        cnt[i] = c;
        ed[p].pb(i);
    }

    dfs(root);
    bool f = true;
    for (int i = 0; i < n; ++i) {
        if (use[i]) {
            f = false;
            cout << i + 1 << ' ';
        }
    }

    if (f) {
        cout << -1 << '\n';
    }
}
