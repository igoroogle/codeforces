#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 2E18;
int par1[200010], par2[200010], len1[200010], len2[200010];
vector<int> a[200010], b[200010];
int getroot1(int x) {
    if (par1[x] == -1) {
        return x;
    }

    par1[x] = getroot(par1[x]);
    return par1[x];
}

int getroot2(int x) {
    if (par2[x] == -1) {
        return x;
    }

    par2[x] = getroot(par2[x]);
    return par2[x];
}

void unions1(int u, int v) {
    u = getroot1(u);
    v = getroot1(v);
    if (len1[u] < len1[v]) {
        par1[u] = v;
    } else if (len1[u] > len1[v]) {
        par1[v] = u;
    } else {
        par1[u] = par1[v];
        ++len1[v];
    }
}

void unions2(int u, int v) {
    u = getroot2(u);
    v = getroot2(v);
    if (len2[u] < len2[v]) {
        par2[u] = v;
    } else if (len2[u] > len2[v]) {
        par2[v] = u;
    } else {
        par2[u] = par2[v];
        ++len2[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, q, ans = 0. x, y;
    cin >> n >> m >> q;
    if (q == 0) {
        cout << n + m - 1 << endl;
        return 0;
    }

    for (int i = 0; i <= n; ++i) {
        par1[i] = -1;
        len1[i] = 0;
    }

    for (int i = 0; i <= m; ++i) {
        par2[i] = -1;
        len2[i] = 0;
    }

    while(q--) {
        cin >> x >> y;
        --x;
        --y;
        a[x].pb(y);
        b[y].pb(x);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++i)
    }
}
