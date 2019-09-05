#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const int DL = 1000010;
const ll MOD = 1E9 + 7;
ll dp[1000012];
int an[1000010], a[100010];
bool comp(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
    if (a.size() < b.size()) {
        return 1;
    }

    if (a.size() > b.size()) {
        return 0;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < b[i]) {
            return 1;
        } else if (a[i] > b[i]) {
            return 0;
        }
    }
}

bool eqv(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
    if (a.size() != b.size()) {
        return 0;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

vector<pair<int, int>> b[1000001];
int main() {
    int nh, n, m, i, j, k;
    ll ans = 1;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (i = 3; i < DL; ++i) {
        dp[i] = (dp[i - 1] * ll(i)) % MOD;
    }



    cin >> nh >> m;
    for (k = 0; k < nh; ++k) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++an[a[i]];
        }

        for (i = 0; i < n; ++i) {
            if (an[a[i]] != 0) {
                b[a[i]].pb(mp(k, an[a[i]]));
                an[a[i]] = 0;
            }
        }
    }

    sort(b + 1, b + m + 1, comp);
    b[m + 2].pb(mp(-1, -1));
    ll to_ans = 1;
    for (i = 2; i <= m + 1; ++i) {
        if (!eqv(b[i], b[i - 1])) {
            ans = (ans * dp[to_ans]) % MOD;
            to_ans = 1;
        } else {
            ++to_ans;
        }
    }
    cout << ans << endl;
}
