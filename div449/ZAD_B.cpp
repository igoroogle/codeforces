#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_beck
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
string s;
int main() {
    ios_base::sync_with_stdio(0);
    ll k, p, ans = 0, t, j, toans;
    cin >> k >> p;
    for (ll i = 1; i <= k; ++i) {
        j = i;
        toans = i % p;
        while (j > 0) {
            toans = (toans * ll(10) + (j % ll(10))) % p;
            j /= ll(10);
        }
        ans = (ans + toans) % p;
    }
    cout << ans << endl;
}
