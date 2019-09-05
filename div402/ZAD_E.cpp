#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
string a, b, c, d;
map <string, int> t;
int val[2][5003][1003], ans[2][1003];
int main() {
    ios_base::sync_with_stdio(0);
    int i, j, n, m, kl = 1, ind, ind2, ind3;
    cin >> n >> m;
    for (i = 0; i < m; ++i) {
        val[1][0][i] = 1;
    }

    for (i = 0; i < n; ++i) {
        cin >> a >> b >> b;
        ind = kl++;
        t[a] = ind;

        if ((b[0] == '0') || (b[0] == '1')) {

            reverse(b.begin(), b.end());
            for (j = 0; j < m; ++j) {
                val[0][ind][j] = int(b[j] - '0');
                val[1][ind][j] = int(b[j] - '0');
                ans[0][j] += int(b[j] - '0');
                ans[1][j] += int(b[j] - '0');
                //cout << "vals " << val[0][ind][j] << ' ' << val[1][ind][j] << ' ' << ind << ' ' << j << endl;
            }
            continue;
        }

        cin >> c >> d;
        if (b == "?") {
            ind2 = 0;
        } else {
            ind2 = t[b];
        }

        if (d == "?") {
            ind3 = 0;
        } else {
            ind3 = t[d];
        }

        for (j = 0; j < m; ++j) {
            //cout << "val " << val[0][ind][j] << ' ' << val[1][ind][j] << ' ' << ind << ' ' << ind2 << ' ' << " " << j << endl;
            if (c == "AND") {
                val[0][ind][j] = val[0][ind2][j] & val[0][ind3][j];
                val[1][ind][j] = val[1][ind2][j] & val[1][ind3][j];
                ans[0][j] += val[0][ind][j];
                ans[1][j] += val[1][ind][j];
            } else if (c == "OR") {
                val[0][ind][j] = val[0][ind2][j] | val[0][ind3][j];
                val[1][ind][j] = val[1][ind2][j] | val[1][ind3][j];
                ans[0][j] += val[0][ind][j];
                ans[1][j] += val[1][ind][j];
            } else if (c == "XOR") {
                val[0][ind][j] = val[0][ind2][j] ^ val[0][ind3][j];
                val[1][ind][j] = val[1][ind2][j] ^ val[1][ind3][j];
                ans[0][j] += val[0][ind][j];
                ans[1][j] += val[1][ind][j];
            }
        }
    }

    for (i = m - 1; i >= 0; --i) {
        //cout << ans[0][i] << ' ' << ans[1][i] << ' ' << i << endl;
        if (ans[0][i] <= ans[1][i]) {
            cout << '0';
        } else {
            cout << '1';
        }
    }
    cout << endl;

    for (i = m - 1; i >= 0; --i) {
        if (ans[0][i] >= ans[1][i]) {
            cout << '0';
        } else {
            cout << '1';
        }
    }
    cout << endl;
}
