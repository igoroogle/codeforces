#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

bool is_prost(ll n) {
    if (n == 2) {
        return true;
    }

    if (n % ll(2) == 0) {
        return false;
    }

    for (ll i = 3; i * i <= n; ++i) {
        if (n % i == ll(0)) {
            return false;
        }
    }

    return true;
}

ll dp[1010];
ll to_ans(ll n) {
    if (n == ll(0))
        return ll(0);

    if ((n <= ll(1000)) && (dp[n] != 0))
        return dp[n];

    ll mx = 1E18;
    for (ll i = n; i >= max(n - ll(1000), ll(2)); --i) {
            cout << i << endl;
        if ((n - i != ll(1)) && (is_prost(i))) {
            mx = min(ll(1) + to_ans(n - i), mx);
        }
    }

    if (n <= ll(1000)) {
        dp[n] = mx;
    }

    return mx;
}
int main() {
    ll n;
    cin >> n;
    dp[1] = 1E18;
    dp[2] = ll(1);
    dp[3] = ll(1);
    cout << to_ans(n) << endl;
    return 0;
}
