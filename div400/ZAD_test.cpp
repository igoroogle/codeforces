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
    freopen("input.txt", "w", stdout);
    int n = 100000;
    srand(time(0));
    cout << n << ' ' << -2 << endl;
    for (int i = 0; i < n; ++i) {
        cout << rand() << ' ';
    }
}
