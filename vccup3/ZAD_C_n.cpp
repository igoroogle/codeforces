#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 1E18;
ll dp[203][203], a[203][203], f[203];
ll ans(ll i, ll j) {
    if (dp[i][j] != INF) {
        return dp[i][j];
    }

    dp[i][j] = ans(f[i], j - 1);
    return dp[i][j];
}

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    return a / gcd(a, b) * b;
}

int main() {
    ll i, j, k, n, answ = 0, mn = 0, answr = 0;
    cin >> n;
    for (i = 0; i < 203; ++i) {
        for (j = 0; j < 203; ++j) {
            a[i][j] = INF;
            dp[i][j] = INF;
        }
    }

    for (i = 0; i < n; ++i) {
        cin >> f[i];
        --f[i];
        dp[i][0] = i;
        dp[i][1] = f[i];
        a[i][f[i]] = 1;
    }

    for (k = 0; k < n; ++k) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    for (i = 0; i < n; ++i) {
        if (a[i][i] != INF) {
            answ = lcm(a[i][i], answ);
        }
    }

    for (i = 0; i < n; ++i) {
        j = 0;
        while (a[ans(i, j)][ans(i, j)] == INF) {
            ++j;
        }

        while (answr < j) {
            answr += answ;
        }
    }

    if (answr == 0) {
        answr = answ;
    }

    cout << answr << endl;
}
