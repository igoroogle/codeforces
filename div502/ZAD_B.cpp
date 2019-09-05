#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll kl[5];
int main() {
    ios_base::sync_with_stdio(0);
    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int a1 = (a[i] - '0');
        int b1 = (b[i] - '0');
        int vl = (a1 << 1) | b1;
        for (int j = 0; j < 4; ++j) {
            if (((j >> 1) | (j & 1)) != (a1 | (j & 1))) {
                ans += kl[j];
                continue;
            }

            if ((((j >> 1)) | b1) != (a1 | b1)) {
                ans += kl[j];
                continue;
            }
        }
        ++kl[vl];
    }

    cout << ans << '\n';
}
