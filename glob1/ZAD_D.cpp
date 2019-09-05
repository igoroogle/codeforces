#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int dp[1000010], a[1000010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    /*for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;*/
    int i = -1, j = -1, k = -1;
    for (int p = 1; p <= n; ++p) {
        if (i == -1) {
            i = p;
        } else if (j == -1) {
            if (a[p] != a[i]) {
                j = p;
            }
        } else if (k == -1) {
            if (a[p] != a[j]) {
                k = p;
            }
        } else if (a[k] != a[p]) {
            i = j;
            j = k;
            k = p;
        }
        //cout << a[p] << ' ' <<  i << ' ' << j << ' ' << k << ' ' << p << endl;

        if ((p != n) && (a[p + 1] == a[p])) {
            continue;
        }

        if (j == -1) {
            for (int u = i; u <= p; ++u) {
                dp[u] = (u - i + 1) / 3;
            }
            continue;
        }

        if (k == -1) {
            for (int u = j; u <= p; ++u) {
                dp[u] = dp[j - 1] + (u - j + 1) / 3;
            }
            continue;
        }


        //cout << "hh\n";
        if ((a[k] != a[j] + 1) || (a[j] != a[i] + 1)) {
            for (int u = k; u <= p; ++u) {
                dp[u] = dp[k - 1] + (u - k + 1) / 3;
            }
            continue;
        }
        //cout << "uhh\n";

        int vl = min(j - i, k - j);
        vl = min(p - k + 1, vl);
        //cout << vl << endl;

        for (int u = k; u <= p; ++u) {
            dp[u] = dp[u - 1];
        }

        for (int cnt = 1; cnt <= vl; ++cnt) {
            cout << p << ' ' << dp[k + cnt - 1] << ' ' << k + cnt - 1 << ' ' << j - cnt - 1 << ' ' << dp[j - cnt - 1] << ' ' << j << endl;
            dp[k + cnt - 1] = max(dp[k + cnt - 1], dp[j - cnt - 1] + (k - j - cnt) / 3 + 1);
        }

        for (int u = k; u <= p; ++u) {
            dp[u] = max(dp[u - 1], dp[u]);
        }

        for (int u = k + 2; u <= p; ++u) {
            dp[u] = max(dp[u], dp[u - 3] + 1);
        }
    }


    cout << dp[n] << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << ' ';
    }
}
