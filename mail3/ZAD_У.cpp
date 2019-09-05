#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define int ll
using namespace std;
typedef long long ll;
typedef long double ld;
const int LEN = 100010;
int d[LEN], seg[LEN];
vector<int> ed[LEN];

void dfs(int v) {
    if (ed[v].empty()) {
        d[v] = 1;
        ++seg[1];
        return;
    }

    for (auto u : ed[v]) {
        dfs(u);
        d[v] += d[u];
    }

    ++seg[d[v]];
}

main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ed[x].pb(i);
    }

    dfs(0);
    int ans = 0;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        while (ans < i) {
            ++j;
            ans += seg[j];
        }
        cout << j << ' ';
    }
}
