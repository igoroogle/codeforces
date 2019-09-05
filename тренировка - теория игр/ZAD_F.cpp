#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
const int DL = 10002;
typedef long long ll;
int a[100010], vl[100010];
int main() {
    freopen("many-heaps.in", "r", stdin);
    freopen("many-heaps.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k, x, cur;
        int ans = 0;
        cin >> n >> k;
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            vl[i] = x;
            a[i] = (x % (k + 1)) ^ a[i - 1];
        }

        if (a[n] != 1) {
            for (int i = 1; i <= n; ++i) {
                cur = a[n] ^ a[i] ^ a[i - 1] ^ 1;
                if ((cur <= k) && (vl[i] > cur) && (vl[i] % (k + 1) != cur)) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}
