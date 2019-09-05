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
int use[27][27][5001];
ll b[27];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
        k = i;
        for (int j = 0; j < n; ++j) {
            ++use[s[i] - 'a'][s[k] - 'a'][j];
            ++k;
            if (k == n) {
                k = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ++b[s[i] - 'a'];
    }

    ld ans = 0;
    bool f;
    ll tans;
    for (int i = 0; i < 26; ++i) {
        if (b[i] == 0) {
            continue;
        }
        ld tans = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 26; ++k)
                if (use[i][k][j] == 0) {
                    continue;
                }
                tans = max(tans, ld(1) / use[i][k][j]);
            }
        ans += tans / ld(b[i]);
    }

    cout << fixed << setprecision(11) << ans << endl;
    return 0;
}
