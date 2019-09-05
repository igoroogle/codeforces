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
int a[111];

int main() {
    ios_base::sync_with_stdio(0);
    int n, sm = 0, mx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
        mx = max(mx, a[i]);
    }

    int ans = mx;
    for (;;) {
        int ssm = 0;
        for (int i = 0; i < n; ++i) {
            ssm += ans - a[i];
        }
        if (ssm > sm) {
            break;
        }
        ++ans;
    }

    cout << ans << '\n';
}
