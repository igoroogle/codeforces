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
const ll INF = 1E18;
vector<int> g[300010];
string s;
int use[300010], color[300010];
int ans[27][300002];
vector<int> cicle;

/*void dfs (int v) {
	color[v] = 1;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (color[to] == 0) {
			dfs(to);
		}
		else if (color[to] == 1) {
			cout << -1 << '\n';
			exit(0);
		}
	}
	color[v] = 2;
}*/

void dfs(int v) {
    color[v] = 1;
    for (auto u : g[v]) {
        if (color[u] == 1) {
            cout << -1 << '\n';
            exit(0);
        } else if (color[u] == 0) {
            dfs(u);
        }
    }
    color[v] = 2;
}

int get_ans(int let, int v) {
    if (ans[let][v] != -1) {
        return ans[let][v];
    }

    ans[let][v] = 0;
    for (auto u : g[v]) {
        ans[let][v] = max(get_ans(let, u), ans[let][v]);
    }

    if (let == int(s[v] - 'a')) {
        ++ans[let][v];
    }
    return ans[let][v];
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    cin >> s;
    while (m--) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = -1;
        }
    }

    int gans = 0;
     for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            gans = max(gans, get_ans(i, j));
        }
    }
    cout << gans << endl;
}
