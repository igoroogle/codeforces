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
    map <ll, int> t;
    int n;
    ll x, y;
    cin >> n >> x;
    int ans = INF;

    for (int i = 0; i < n; ++i) {
        cin >> y;
        if (t[y] > 0) {
            ans = min(ans, t[y] - 1);
        } else if (t[(y & x)] > 0) {
            ans = min(ans, t[(y & x)]);
        }

        t[y] = 1;
        if (t[(y & x)] == 0) {
            t[(y & x)] = 2;
        }

    }

    if (ans == INF) {
        ans = -1;
    }

    cout << ans << '\n';
}
