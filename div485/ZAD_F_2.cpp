#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int parent[(1 << 22) + 1], len[(1 << 22) + 1];
char use[(1 << 22) + 1];
int a[(1 << 22) + 1];
int ans;

int getroot(const int& v) {
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

    if ((use[u] & 1) && (use[v] & 1)) {
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

    if ((use[u] & 1) || (use[v] & 1)) {
        use[to] |= 1;
    }
}

void goForward(const int& mask, const int& n) {
    if (use[mask] & 2) {
        return;
    }

    use[mask] |= 2;

    for (int i = 0; i < n; ++i) {
        if ((1 << i) & mask) {
            int to = ((~(1 << i)) & mask);
            goForward(to, n);

            if (use[to] & 4) {
                use[mask] |= 4;
                unionTo(mask, to);
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < (1 << 22); ++i) {
        parent[i] = -1;
    }

    int n, m;
    cin >> n >> m;
    ans = m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        use[a[i]] |= 5;
    }

    for (int i = 0; i < m; ++i) {
        int to = (((1 << n) - 1) & (~a[i]));
        goForward(to, n);
        unionTo(a[i], to);
    }

    cout << ans << '\n';
}
