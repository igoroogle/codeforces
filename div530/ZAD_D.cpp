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
vector<int> ed[100010];
ll ans[100010], sm[100010];

void dfs(int v, int h, ll sum) {
    if ((h % 2) && (sm[v] != ll(-1))) {
        cout << -1 << '\n';
        exit(0);
    } else if ((!(h % 2)) && (sm[v] == ll(-1))) {
        cout << -1 << '\n';
        exit(0);
    }

    if ((sm[v] != -1) && (sum != sm[v])) {
        cout << -1 << '\n';
        exit(0);
    }

    for (auto u : ed[v]) {
        if (sm[u] == -1) {
            continue;
        }

        if (sm[u] < sum) {
            cout << -1 << '\n';
            exit(0);
        }

        ans[u] = sm[u] - sum;
    }

    for (auto u : ed[v]) {
        dfs(u, h + 1, sum + ans[u]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        --v;
        ed[v].pb(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> sm[i];
    }

    ans[0] = sm[0];
    dfs(0, 0, sm[0]);
    ll ansv = 0;
    for (int i = 0; i < n; ++i) {
        ansv += ans[i];
    }

    cout << ansv << '\n';
    return 0;
}
