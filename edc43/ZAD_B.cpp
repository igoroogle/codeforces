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
    ll n, m, k;
    cin >> n >> m >> k;
    if (k < n) {
        cout << k + ll(1) << ' ' << "1 \n";
        return 0;
    }

    k -= n;
    ++k;
    ll x = n - (k / (m - ll(1)));
    if (!(k % (m - ll(1)))) {
        ++x;
    }

    k -= (n - x) * ll(m - 1);
    ll y;
    if ((n - x) % ll(2) == 0) {
        y = ll(1) + k;
    } else {
        y = m - k + ll(1);
    }
    cout << x << ' ' << y << endl;
}
