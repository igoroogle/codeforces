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

int main() {
    ios_base::sync_with_stdio(0);
    int n, v, ans = 0, t = 0;
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) {
        int vt = min(n - i, v);
        ans += (vt - t) * i;
        t = vt - 1;
    }
    cout << ans << '\n';
}
