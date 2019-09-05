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
const int INF = 1E9 + 7;

int f[300010], num[300010], leav[300010];
vector<int> ed[300010];

void dfs(int v) {
    if (ed[v].empty()) {
        num[v] = 1;
        leav[v] = 1;
        return;
    }

    for (auto u: ed[v]) {
        dfs(u);
        leav[v] += leav[u];
    }

    num[v] = 1;
    for (auto u : ed[v]) {
        if (f[v]) {
            num[v] = max(leav[v] - leav[u] + num[u], num[v]);
        } else {
            num[v] += num[u] - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ed[x].pb(i);
    }

    dfs(0);
    cout << num[0] << '\n';
}
