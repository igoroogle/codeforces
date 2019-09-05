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
const ll INF = 1E18;

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, a, b;
    ld ans = INF;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        ans = min(ld(a * m) / ld(b), ans);
    }
    cout << fixed << setprecision(11) << ans << endl;
}
