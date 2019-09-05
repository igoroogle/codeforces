#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
ll a[110][110], b[110][110], n, m, k, x, y;
ll get_ans(ll f, ll s) {
    ll an;
    if (n > 2) {
        an = k / (ll(n + n - 2) * m) * b[f][s];
    } else {
        an = k / (n * m) * b[f][s];
    }

    an += a[f][s];
    return an;
}

int main() {
    cin >> n >> m >> k >> x >> y;
    ll g, i, j;
    if (n > 2) {
        g = k % (ll(n + n - 2) * m);
    } else {
        g = k % (n * m);
    }


    for (i  = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            ++b[i][j];
        }
    }

    for (i  = n - 2; i > 0; --i) {
        for (j = 0; j < m; ++j) {
            ++b[i][j];
        }
    }

    for (i  = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (g > 0) {
                --g;
                ++a[i][j];
            }
        }
    }

    for (i  = n - 2; i > 0; --i) {
        for (j = 0; j < m; ++j) {
            if (g > 0) {
                --g;
                ++a[i][j];
            }
        }
    }


    cout << get_ans(0, 0) << ' ' << get_ans(n - 1, m - 1) << ' ' << get_ans(x - 1, y - 1) << endl;
}
