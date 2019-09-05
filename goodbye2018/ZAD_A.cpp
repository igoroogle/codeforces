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
    ll y, b, r;
    cin >> y >> b >> r;
    ll ans = min(r, min(b + ll(1), y + ll(2)));
    cout << ans + ans - ll(1) + ans - ll(2) << '\n';
}
