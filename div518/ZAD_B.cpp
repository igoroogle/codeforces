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
const int INF = 1E9;
const ld TM = 0.006;

int main() {
    ios_base::sync_with_stdio(0);
    int n, t, a, ans = 1, x;
    ld vl = INF;
    cin >> n >> t >> a;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (abs(ld(t) - TM * ld(x) - ld(a)) < vl) {
            ans = i + 1;
            vl = abs(ld(t) - TM * ld(x) - ld(a));
        }
    }

    cout << ans << '\n';
}
