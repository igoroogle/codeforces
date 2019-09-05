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
const ll INF = 1E18;
const ll MOD = 1E9 + 9;
vector<int> ed[200010];
int dp[2][200010];

int dfs(int v, int t, int pr) {
    if (dp[t][v] != 0) {
        return dp[t][v] - 1;
    }

    int a = 0, b = 0, c = 0, vl1, vl2;
    for (auto u : ed[v]) {
        if (u == pr) {
            continue;
        }
        vl1 = dfs(u, 0, v);
        vl2 = dfs(u, 1, v);
        if (vl1 + vl2 == 2) {
            ++c;
        } else if (vl1 == 1) {
            ++a;
        } else if (vl2 == 1) {
            ++b;
        } else {
            dp[t][v] = 1;
            return 0;
        }
    }


    if (((a + t) % 2) && (c == 0)) {
        dp[t][v] = 1;
        return 0;
    } else {
        dp[t][v] = 2;
        return 1;
    }
}

int showAns(int v, int t, int pr) {
    int a = 0, b = 0, c = 0, vl1, vl2;
    vector<int> aa;
    vector<int> bb;
    vector<int> cc;
    for (auto u : ed[v]) {
        if (u == pr) {
            continue;
        }
        vl1 = dfs(u, 0, v);
        vl2 = dfs(u, 1, v);
        if (vl1 + vl2 == 2) {
            ++c;
            cc.pb(u);
        } else if (vl1 == 1) {
            ++a;
            aa.pb(u);
        } else if (vl2 == 1) {
            ++b;
            bb.pb(u);
        } else {
            cout << "NO\n";
            exit(0);
        }
    }

    if (((a + t) % 2) && (c == 0)) {
        cout << "NO\n";
        exit(0);
    }

    if ((a + t) % 2) {
        aa.pb(cc.back());
        cc.pop_back();
    }

    for (auto u : bb) {
        showAns(u, 1, v);
    }

    for (auto u : cc) {
        showAns(u, 1, v);
    }

    cout << v + 1 << '\n';
    for (auto u : aa) {
        showAns(u, 0, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, v, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 0) {
            v = i;
            continue;
        }
        --x;
        ed[x].pb(i);
        ed[i].pb(x);
    }

    if (dfs(v, 0, -1) == 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    showAns(v, 0, -1);
}
