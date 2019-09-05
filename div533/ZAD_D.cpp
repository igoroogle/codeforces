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
vector<pair<int, int>> q[9];
vector<pair<int, int>> qq;
int ss[10];
char a[1003][1003];
int ans[10];
bool use[10];

bool is_cor(pair<int, int> val, int n, int m) {
    if ((val.x < 0) || (val.y < 0) || (val.x >= n) || (val.y >= m)) {
        return false;
    }

    return (a[val.x][val.y] == '.');
}



int main() {
    ios_base::sync_with_stdio(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < p; ++i) {
        cin >> ss[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (isalnum(a[i][j])) {
                q[a[i][j] - '1'].pb(mp(i, j));
            }
        }
    }

    int vt = 0, cur = 0;
    while (vt < p) {
        if (q[cur].empty()) {
            if (!use[cur]) {
                ++vt;
                use[cur] = true;
            }
            cur = (cur + 1) % p;
            continue;
        }

        for (int k = 0; k < ss[cur]; ++k) {
            if (q[cur].empty()) {
                break;
            }

            qq.clear();
            for (auto val : q[cur]) {
                if (is_cor(mp(val.x + 1, val.y), n, m)) {
                    qq.pb(mp(val.x + 1, val.y));
                    a[val.x + 1][val.y] = char(cur + '1');
                }

                if (is_cor(mp(val.x - 1, val.y), n, m)) {
                    qq.pb(mp(val.x - 1, val.y));
                    a[val.x - 1][val.y] = char(cur + '1');
                }

                if (is_cor(mp(val.x, val.y + 1), n, m)) {
                    qq.pb(mp(val.x, val.y + 1));
                    a[val.x][val.y + 1] = char(cur + '1');
                }

                if (is_cor(mp(val.x, val.y - 1), n, m)) {
                    qq.pb(mp(val.x, val.y - 1));
                    a[val.x][val.y - 1] = char(cur + '1');
                }
            }
            q[cur] = qq;
        }
        cur = (cur + 1) % p;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isalnum(a[i][j])) {
                ++ans[a[i][j] - '1'];
            }
        }
    }

    for (int i = 0; i < p; ++i) {
        cout << ans[i] << ' ';
    }
}
