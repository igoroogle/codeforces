#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ld EPS = 1E-12;
char a[53][53];
string s;
int p[5];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, sx, sy, fx, fy, ans = 0, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'E') {
                fx = i;
                fy = j;
            }
        }
    }
    cin >> s;

    for (int i = 0; i < 4; ++i) {
        p[i] = i;
    }

    bool f;
    for (int per = 0; per < 24; ++per) {
        /*for (int j = 0; j < 4; ++j) {
            cout << p[j] << ' ';
        }
        cout << endl;*/
        f = false;
        x = sx;
        y = sy;
        for (size_t k = 0; k < s.length(); ++k) {
            if (p[s[k] - '0'] == 0) {
                --x;
            } else if (p[s[k] - '0'] == 1) {
                ++x;
            } else if (p[s[k] - '0'] == 2) {
                --y;
            } else if (p[s[k] - '0'] == 3) {
                ++y;
            }

            if ((x < 0) || (y < 0) || (x  >= n) || (y >= m) || (a[x][y] == '#')) {
                break;
            }

            if (a[x][y] == 'E') {
                f = true;
                break;
            }
        }

        if (f) {
            ++ans;
        }
        next_permutation(p, p + 4);
    }

    cout << ans << endl;
}
