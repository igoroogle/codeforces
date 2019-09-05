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
typedef pair<int, int> pii;
const int INF = 1E9;
int a[111], b[111], ans[111][111], hw[111][111];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ans[i][j];
            if (ans[i][j] != 0) {
                ans[i][j] = min(a[j], b[i]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
