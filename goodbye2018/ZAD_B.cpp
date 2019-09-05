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

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ll x, y, sx = 0, sy = 0;
    cin >> n;
    for (int i = 0; i < n + n; ++i) {
        cin >> x >> y;
        sx += x;
        sy += y;
    }

    cout << sx / n << ' ' << sy / n << '\n';
}
