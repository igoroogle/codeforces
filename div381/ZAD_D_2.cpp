#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
const ll DL = 400010;
const ll INF = 2E18;
ll a[DL], tin[DL], tout[DL], ss = 0, vl[DL], r[DL], kl = 0, tans[DL], f[DL];
void upd(int k, ll x) {
    int i = k;
    while (i < DL) {
        f[i] += x;
        i = i | (i + 1);
    }
}

ll get(int r) {
    int i = r;
    ll ans = 0;
    while (i >= 0) {
        ans = f[i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}

vector<ll> ed[DL], w[DL], xx[DL], um[DL], zn[DL];
map<ll, ll> to_ans;
set<ll> nx;
void dfs(ll v, ll sum) {
    for (size_t i = 0; i < ed[v].size(); ++i) {
        a[ss] = sum;
        tin[v] = ss++;
        r[kl++] = vl[v] + sum;
        for (size_t i = 0; i < ed[v].size(); ++i) {
            dfs(ed[v][i], sum + w[v][i]);
        }

        a[ss] = sum;
        tout[v] = ss++;
    }
}

int main() {
    ll n, i, x, y;
    cin >> n;
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &vl[i]);
    }

    for (i = 1; i < n; ++i) {
        scanf("%I64d%I64d", &x, &y);
        --x;
        ed[i].pb(x);
        w[i].pb(y);
    }

    dfs(0, 0);
    kl = 1;
    sort(r, r + n);
    for (i = 1; i < n; ++i) {
        if (r[i] != r[i - 1]) {
            r[kl++] = r[i];
        }
    }

    nx.insert(INF);
    for (i = 0; i < kl; ++i) {
        nx.insert(r[i]);
        to_ans[r[i]] = i;
    }

    to_ans[INF] = kl;

    for (i = 0; i < n; ++i) {
        xx[tin[i]].pb(i);
        zn[tin[i]].pb(vl[i] + a[tin[i]]);
        um[tin[i]].pb(1);

        zn[tout[i] - 1].pb(vl[i] + a[tin[i]]);
        xx[tout[i] - 1].pb(i);
        um[tout[i] - 1].pb(-1);
    }

    for (i = 0; i < ss; ++i) {
        x = to_ans[*nx.lower_bound(a[i])];
        upd(int(to_ans[x]), 1);
    }
}
