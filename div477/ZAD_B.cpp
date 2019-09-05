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
    ll n, a, b, s1, x, sm, ans = 0;
    multiset<ll> val;
    cin >> n >> a >> b >> s1;
    sm = s1;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        val.insert(-x);
        sm += x;
    }

    while (s1 * a < b * sm) {
        sm += *val.begin();
        val.erase(val.begin());
        ++ans;
    }

    cout << ans << endl;
}
