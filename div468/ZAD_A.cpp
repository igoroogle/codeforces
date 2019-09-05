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
    ll a, b, ans = 0, sa = 1, sb = 1;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    while (a < b) {
        if (sa < sb) {
            ans += sa;
            ++a;
            ++sa;
        } else {
            ans += sb;
            --b;
            ++sb;
        }
    }
    cout << ans << endl;
}
