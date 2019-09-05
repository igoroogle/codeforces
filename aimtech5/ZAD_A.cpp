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
const int INF = 1E9;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, mnx = INF, mny = INF, mxx = -INF, mxy = -INF;
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            if (c == 'B') {
                mnx = min(mnx, i);
                mxx = max(mxx, i);
                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
    }

    cout << ((mxx + mnx) >> 1) << ' ' << ((mxy + mny) >> 1) << '\n';
}
