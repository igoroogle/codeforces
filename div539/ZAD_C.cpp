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
const int LEN = (1 << 20) + 3;
ll a[2][LEN];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int sm = 0;
    ll ans = 0;
    a[1][0] = 1;


    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sm ^= x;
        ans += a[i % 2][sm];
        //cout << i % 2 << ' ' << sm << ' ' << a[i % 2][sm] << endl;
        ++a[i % 2][sm];
    }

    cout << ans << '\n';
}
