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
char a[300010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ll x, y;
    cin >> n >> x >> y >> a;
    int m = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            a[m++] = a[i];
        }
    }
    n = m;

    ll zer = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            ++zer;
        }
    }

    if (zer == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << min(ll(zer - 1) * x + y, zer * y) << endl;
}
