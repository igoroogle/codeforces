#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll ans[5007];
int main() {
    ios_base::sync_with_stdio(0);
    ans[0] = 1;
    ll n;
    cin >> n;
    char c = 's';
    for (ll i = 0; i < n; ++i) {
        if (c == 's') {
            for (ll j = n; j > 0; --j) {
                ans[j - 1] = (ans[j - 1] + ans[j]) % MOD;
            }
        }
        cin >> c;
        if (c == 'f') {
            for (ll j = n; j > 0; --j) {
                ans[j] = ans[j - 1];
            }
            ans[0] = 0;
        }
    }
    ll toans = 0;
    for (ll i = 0; i <= n; ++i) {
        toans = (toans + ans[i]) % MOD;
    }
    cout << toans << endl;
}
