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
const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll corpr = 2, corsuf = 2;

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            break;
        }
        ++corpr;
    }

    for (int i = n - 2; i >= 0; --i) {
        if (s[i] != s[i + 1]) {
            break;
        }
        ++corsuf;
    }

    //cout << corpr << ' ' << corsuf << endl;
    if (s[0] == s[n - 1]) {
        cout << (corpr * corsuf) % MOD << '\n';
    } else {
        cout << (corpr + corsuf - ll(1)) % MOD << '\n';
    }
}
