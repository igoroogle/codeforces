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
char a[103][103];
int sm[103][103];
int main() {
    ios_base::sync_with_stdio(0);
    int i, j, n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool f = true;
            for (int p = 0; p < k; ++p) {
                if ((i + p < n) && (a[i + p][j] == '.')) {
                    continue;
                } else {
                    f = false;
                    break;
                }
            }

            if (f) {
                for (int p = 0; p < k; ++p) {
                    ++sm[i + p][j];
                }
            }

            f = true;
            for (int p = 0; p < k; ++p) {
                if ((j + p < n) && (a[i][j + p] == '.')) {
                    continue;
                } else {
                    f = false;
                    break;
                }
            }

            if (f) {
                for (int p = 0; p < k; ++p) {
                    ++sm[i][j + p];
                }
            }
        }
    }

    int mx = 0, x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mx < sm[i][j]) {
                mx = sm[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << x + 1 << ' ' << y + 1 << endl;
}
