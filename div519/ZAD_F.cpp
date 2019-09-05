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
const int DL = 300003;
const int INF = 1E9 + 2;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int del[DL], pr[DL];
vector<int> a[DL];

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < DL; ++i) {
        pr[i] = i;
    }

    for (int i = 2; i < DL; ++i) {
        if (pr[i] == i) {
            for (int j = i + i; j < DL; j += i) {
                pr[j] = min(pr[j], i);
            }
        }
    }

    int n, x, gd = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 1) {
            cout << 1 << '\n';
            return 0;
        }
        gd = gcd(x, gd);


        //cout << endl;
        while (x > 1) {
            if ((a[i].empty()) || (a[i].back() != pr[x])) {
                a[i].pb(pr[x]);
                //cout << pr[x] << ' ';
            }
            x /= pr[x];
        }
        //cout << endl;

        for (int msk = 0; msk < (1 << int(a[i].size())); ++msk) {
            int val = 1;
            for (int j = 0; j < int(a[i].size()); ++j) {
                if ((1 << j) & msk) {
                    val *= a[i][j];
                }
            }
            ++del[val];
        }

    }

    if (gd > 1) {
        cout << -1 << '\n';
        return 0;
    }

    int ans = n;
    for (int i = 0; i < n; ++i) {
        int m = a[i].size();
        vector<int> dp(1 << m), cnt(1 << m);
        fill(dp.begin(), dp.end(), INF);
        for (int msk = (1 << m) - 1; msk >= 0; --msk) {
            int val = 1;
            for (int j = 0; j < m; ++j) {
                if ((1 << j) & msk) {
                    val *= a[i][j];
                }
            }
            cnt[msk] += del[val];
            int j = 0;
            if (msk != 0) {
                j = (msk & (msk - 1));
                cnt[0] -= cnt[msk];
            }

            while (j > 0) {
                cnt[j] -= cnt[msk];
                j = ((j - 1) & msk);
            }

            if (cnt[msk] > 0) {
                //cout << msk << ' ' << cnt[msk] << endl;
                dp[((1 << m) - 1) ^ msk] = 1;
            }
        }


        for (int msk = (1 << m) - 1; msk >= 0; --msk) {
            if (dp[msk] != 1) {
                continue;
            }

            for (int j = 0; j < m; ++j) {
                if ((1 << j) & msk) {
                    dp[msk  ^ (1 << j)] = 1;
                }
            }
        }

        for (int msk = 1; msk < (1 << m); ++msk) {
            if (dp[msk] == 1) {
                continue;
            }

            int j = msk;
            while (j > 0) {
                dp[msk] = min(dp[msk], dp[j] + dp[(~j) & msk]);
                j = ((j - 1) & msk);
            }
        }

        ans = min(ans, dp[(1 << m) - 1] + 1);
        int vv = 1;
        for (auto cur : a[i]) {
            vv *= cur;
        }
        //cout << vv << ' ' << cnt[0] << ' ' << del[vv] << ' ' << dp[(1 << m) - 1] << endl;
    }

    cout << ans << '\n';
}

/*
6
15015 10010 6006 4290 2730 2310
->6

7
15015 10010 6006 4290 2730 2310 28875
->5

8
15015 10010 6006 4290 2730 2310 28875 22750
->4

*/
