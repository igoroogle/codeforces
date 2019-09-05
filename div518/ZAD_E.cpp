#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
int st[100001], col[100001], ss[100001];
bool use[100001];
vector<int> ed[100001];

int main() {
    ios_base::sync_with_stdio(0);
    queue<int> q;
    int n, k, u, v;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
        ++st[u];
        ++st[v];
    }

    for (int i = 0; i < n; ++i) {
        if (st[i] == 1) {
            q.push(i);
            col[i] = 1;
        }
    }

    int vl = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (use[v]) {
            continue;
        }
        vl = v;

        use[v] = true;

        for (auto u : ed[v]) {
            if (use[u]) {
                continue;
            }

            if (col[u] == 0) {
                col[u] = col[v] + 1;
            }

            if (col[u] != col[v] + 1) {
                cout << "No\n";
                return 0;
            }
            --st[u];
            ++ss[u];
            if ((st[u] <= 1) && (ss[u] >= 3)) {
                q.push(u);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            cout << "No\n";
            return 0;
        }
    }

    if (col[vl] - 1 == k) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
