#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ll MOD = 1E9 + 7;
unordered_map<string, int> t;
int parent[100010], len[100010], ant[100010];
int getroot(int v) {
    if (parent[v] == -1) {
        return v;
    }

    parent[v] = getroot(parent[v]);
    return parent[v];
}

void unions(int u, int v) {
    int u1 = getroot(u), v1 = getroot(v);
    if (u1 == v1) {
        return;
    }


    if (len[u1] < len[v1]) {
        parent[u1] = v;
    } else if (len[u1] > len[v1]) {
        parent[v1] = u1;
        swap(u1, v1);
    } else {
        parent[u1] = v1;
        ++len[v1];
    }

    if (ant[v1] == -1) {
        ant[v1] = ant[u1];
    } else if (ant[u1] != -1) {
        unions(ant[u1], ant[v1]);
        ant[v1] = getroot(ant[v1]);
    }

    if (ant[v1] != -1) {
        ant[ant[v1]] = v1;
    }
}

bool get_cinonim(int u, int v) {
    if ((u == -1) || (v == -1)) {
        return true;
    }

    if (getroot(u) == getroot(v)) {
        return true;
    }

    if ((ant[u] != -1) && (getroot(ant[u]) == getroot(v))) {
        return false;
    }

    if ((ant[v] != -1) && (getroot(ant[v]) == getroot(u))) {
        return false;
    }

    if (ant[u] == -1) {
        return true;
    }

    if (ant[v] == -1) {
        return true;
    }

    return true;
}

string s, ss;
int main() {
    ios_base::sync_with_stdio(0);
    int i, n, m, q, tt, u, v;
    cin >> n >> m >> q;
    for (i = 0; i <= n; ++i) {
        parent[i] = -1;
        len[i] = 0;
        ant[i] = -1;
    }


    for (i = 1; i <= n; ++i) {
        cin >> s;
        t[s] = i;
    }

    while (m--) {
        cin >> tt >> s >> ss;

        u = t[s];
        v = t[ss];
        cout << u << ' ' << v << endl;
        if (tt == 1) {
            if (!get_cinonim(u, v)) {
                cout << "NO\n";
                continue;
            }

            cout << "YES\n";
            unions(u, v);
        } else {
            if (getroot(u) == getroot(v)) {
                cout << "NO\n";
                continue;
            }

            if (!get_cinonim(ant[getroot(u)], getroot(v))) {
                cout << "NO\n";
                continue;
            }

            if (!get_cinonim(ant[getroot(v)], getroot(u))) {
                cout << "NO\n";
                continue;
            }

            ant[getroot(u)] = getroot(v);
            ant[getroot(v)] = getroot(u);
            cout << "YES\n";
            unions(ant[u], u);
            unions(ant[v], v);
        }
    }

    while (q--) {
        cin >> s >> ss;
        u = t[s];
        v = t[ss];
        if (getroot(u) == getroot(v)) {
            cout << "1\n";
        } else if ((ant[u] != -1) && (getroot(ant[u]) == getroot(v))) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
}
