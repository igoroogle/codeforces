#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define em emplace_back
#define sqr(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, a = 0, b = 0, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 1) {
            ++a;
        } else {
            ++b;
        }
    }
    ll ans = min(a, b);
    if (a > b) {
        ans += (a - b) / 3;
    }

    cout << ans << endl;
}
