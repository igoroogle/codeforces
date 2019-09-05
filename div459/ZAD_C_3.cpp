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
bitset<2501> a[5001], b;
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0, j;
    for (int i = 0; i < n - 1; ++i) {
        j = i + 1;
        if ((s[i] != ')') && (s[j] != '(')) {
            a[i][j >> 1] = 1;
            a[j][i >> 1] = 1;
        }
    }

    bool f;
    int vl;
    for (int kl = 4; kl <= n; kl += 2) {
        for (int i = 0; i < n - kl + 1; ++i) {
            j = i + kl - 1;
            b = (a[i] >> (i >> 1)) | (a[j] >> (i >> 1) << 1);
            vl = b.count();
            b = (a[i] >> (j >> 1)) | (a[j] >> (j >> 1) << 1);
            vl -= b.count();
            if (vl > 0) {
                a[i][j >> 1] = 1;
                a[j][i >> 1] = 1;
            } else if ((s[i] != ')') && (s[j] != '(')) {
                if (a[i + 1][(j - 1) >> 1]) {
                    a[i][j >> 1] = 1;
                    a[j][i >> 1] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans += a[i].count();
    }
    cout << ans / 2 << endl;
}
