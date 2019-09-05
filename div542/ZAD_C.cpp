#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 2E9;

bool use[55][55];
char a[55][55];
vector<pair<int, int>> v1, v2;

void dfs(vector<pair<int, int>>& v, int n, int x, int y) {
    if ((x < 0) || (y < 0) || (x >= n) || (y >= n)
        || (a[x][y] == '1') || (use[x][y])) {
        return;
    }
    use[x][y] = true;

    v.em(x, y);
    dfs(v, n, x + 1, y);
    dfs(v, n, x - 1, y);
    dfs(v, n, x, y + 1);
    dfs(v, n, x, y - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    --r1;
    --c1;
    --r2;
    --c2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            use[i][j] = false;
        }
    }
    dfs(v1, n, r1, c1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            use[i][j] = false;
        }
    }
    dfs(v2, n, r2, c2);

    int ans = INF;
    for (auto cur1 : v1) {
        for (auto cur2 : v2) {
            ans = min(sqr(cur1.x - cur2.x) + sqr(cur1.y - cur2.y), ans);
        }
    }
    cout << ans << '\n';
}
