#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[300010];
string s;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i, x, ans = 0, kl = 0, to = 0;
    cin >> n;

    for (i = 0; i < n + n; ++i) {
        cin >> s;
        if (s[0] == 'r') {
            if ((kl <= 0) || ((kl > 0) && (a[kl - 1] == to))) {
                ++to;
                --kl;
                continue;
            }

            kl = 0;
            ++ans;
            ++to;
        } else {
            if (kl < 0) {
                kl = 0;
            }
            cin >> a[kl];
            --a[kl];
            ++kl;
        }
    }

    cout << ans << endl;
    return 0;
}
