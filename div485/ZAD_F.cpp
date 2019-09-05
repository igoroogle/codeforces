#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int parent[(1 << 22) + 1], len[(1 << 22) + 1];
int a[(1 << 22) + 1];
bool use[(1 << 22) + 1], uses[(1 << 22) + 1], user[(1 << 22) + 1];
ll ans;

int getroot(int v) {
    if (parent[v] != -1) {
        parent[v] = getroot(parent[v]);
        return parent[v];
    } else {
        return v;
    }
}

void unionTo(int u, int v) {
    u = getroot(u);
    v = getroot(v);
    if (u == v) {
        return;
    }

    if (use[u] && use[v]) {
        --ans;
    }

    int to = v;
    if (len[u] < len[v]) {
        parent[u] = v;
    } else if (len[u] > len[v]) {
        parent[v] = u;
        to = u;
    } else {
        parent[u] = v;
        ++len[v];
    }

    if (use[u] || use[v]) {
        use[to] = true;
    }
}

void goForward(int& mask, int& n) {
    if (uses[mask]) {
        return;
    }

    uses[mask] = true;

    for (int i = 0; i < n; ++i) {
        if ((1 << i) & mask) {
            int to = ((~(1 << i)) & mask);
            goForward(to, n);

            if (user[to]) {
                user[mask] = true;
                unionTo(mask, to);
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < (1 << 22); ++i) {
        use[i] = false;
        parent[i] = -1;
        len[i] = 0;
    }

    int n, m, x;
    cin >> n >> m;
    ans = m;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        a[i] = x;
        if (x == (1 << n)) {
            continue;
        }

        use[x] = true;
        user[x] = true;
        a[i] = x;
    }

    for (int i = 0; i < m; ++i) {
        if (a[i] == (1 << n)) {
            continue;
        }

        int to = (((1 << n) - 1) & (~a[i]));
        goForward(to, n);
        unionTo(a[i], to);
    }

    cout << ans << '\n';
}
