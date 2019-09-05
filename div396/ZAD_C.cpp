#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ll MOD = 1E9 + 7;
ll dp[1010], mx[1010], mn[1010], vl[3100];
string s;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i, j, mvl = 0;
    cin >> n >> s;
    for (i = 0; i < n; ++i) {
        cin >> vl[i];
    }

    dp[0] = 1;
    for (i = 0; i < n; ++i) {
        mn[i + 1] = INF;
        mx[i + 1] = -INF;
        mvl = INF;
        for (j = i; j >= 0; --j) {
            mvl = min(mvl, vl[s[j] - 'a']);
            if (mvl < i - j + 1) {
                break;
            }
            dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
            if (mx[j] != -INF) {
                mx[i + 1] = max(max(i - j + ll(1), mx[j]), mx[i + 1]);
            }

            if (mn[j] != INF) {
                mn[i + 1] = min(ll(1) + mn[j], mn[i + 1]);
            }
        }
    }

    cout << dp[n] << endl;
    cout << mx[n] << endl;
    cout << mn[n] << endl;
}
