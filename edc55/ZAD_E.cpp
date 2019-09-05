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
const ll LEN = 500010;

ll sum[LEN];
vector<ll> vl[LEN];
vector<ll> ar;

ll a[LEN];

ll getVal(ll l, ll r) {
    if (l > r) {
        return 0;
    }

    return sum[r] - sum[l - 1];
}

ll goAns(vector<ll>& a) {
    ll ans = a[0], sum = 0, min_sum = 0;
    int n = ar.size();
    for (int r = 0; r < n; ++r) {
        sum += a[r];
        ans = max (ans, sum - min_sum);
        min_sum = min (min_sum, sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, c, cVal = 0;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vl[a[i]].pb(i);
        sum[i] += sum[i - 1];
        if (a[i] == c) {
            ++sum[i];
            ++cVal;
        }
    }
    sum[n + 1] = sum[n];

    ll ans = cVal;
    for (int i = 1; i < LEN; ++i) {
        if ((vl[i].empty()) || (i == c)) {
            continue;
        }

        ar.clear();

        for (int j = 0; j < int(vl[i].size()) - 1; ++j) {
            ar.pb(1);
            ar.pb(-getVal(vl[i][j] + 1, vl[i][j + 1] - 1));
        }

        ar.pb(1);
        ans = max(ans, goAns(ar) + cVal);
    }

    cout << ans << '\n';
}
