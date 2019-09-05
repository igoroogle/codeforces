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
bool a[203];
int main() {
    ios_base::sync_with_stdio(0);
    int t, n, k, x;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
                a[i] = false;
        }
        for (int i = 0; i < k; ++i) {
            cin >> x;
            a[x - 1] = true;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, j + 1);
                if ((a[max(0, i - j)]) || (a[min(n - 1, i + j)])) {
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}
