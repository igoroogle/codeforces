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

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, dv, ans = 0;
    cin >> n >> k;
    dv = (k + ll(1)) / ll(2) - ll(1);
    if ((dv == 0) || (n < k - dv)) {
        cout << 0 << endl;
        return 0;
    }

    if (n >= k - 1) {
        cout << dv << endl;
        return 0;
    }

    cout << n - k + dv + ll(1) << endl;
}
