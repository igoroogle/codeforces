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
typedef pair<int, int> pii;

ll nin[11];

int main() {
    ios_base::sync_with_stdio(0);
    vector<ll> an;
    int n;
    cin >> n;
    while (n > 0) {
        an.pb(ll(n % 10));
        n /= 10;
    }
    ll ans = 0, mul = 1;

    nin[0] = 1;
    for (int i = 1; i < 11; ++i) {
        nin[i] = nin[i - 1] * ll(9);
    }

    for (int i = an.size() - 1; i >= 0; --i) {
        ans = max(ans, nin[i]);
        if (an[i] > 0) {
            ans = max(ans, nin[i] * ll(an[i] - 1) * mul);
        }
        mul *= an[i];
    }
    ans = max(ans, mul);
    cout << ans << '\n';
}
