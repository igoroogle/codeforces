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
int parent1[100010], parent2[100010], len1[100010], len2[100010], ant1[100010];
int getroot1(int v) {
    if (parent1[v] == -1) {
        return v;
    }

    parent1[v] = getroot1(parent1[v]);
    return parent1[v];
}

void unions1(int u, int v) {
    int u1 = getroot1(u), v1 = getroot1(v);
    if (u1 == v1) {
        return;
    }

    if (len1[u1] < len1[v1]) {
        parent1[u1] = v1;
        ant1[v1] = max(ant1[v1], ant1[u1]);
    } else if (len1[u1] > len1[v1]) {
        parent1[v1] = u1;
        ant1[u1] = max(ant1[v1], ant1[u1]);
    } else {
        parent1[u1] = v1;
        ++len1[v1];
        ant1[v1] = max(ant1[v1], ant1[u1]);
    }
}

int getroot2(int v) {
    if (parent2[v] == -1) {
        return v;
    }

    parent2[v] = getroot2(parent2[v]);
    return parent2[v];
}

void unions2(int u, int v) {
    int u1 = getroot2(u), v1 = getroot2(v);
    if (u1 == v1) {
        return;
    }

    if (len2[u1] < len2[v1]) {
        parent2[u1] = v1;
    } else if (len2[u1] > len2[v1]) {
        parent2[v1] = u1;
    } else {
        parent2[u1] = v1;
        ++len2[v1];
    }
}

string s, ss;
int main() {
    ios_base::sync_with_stdio(0);
    int i, n, m, q, tt, u, v;
    cin >> n >> m >> q;
    for (i = 0; i <= n; ++i) {
        parent1[i] = -1;
        parent2[i] = -1;
        len1[i] = 0;
        len2[i] = 0;
        ant1[i] = -1;
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
            if (!((getroot1(u) == getroot1(v)) && ((ant[getroot1(u)] == -1) ||  (ant[getroot1(v)] == -1) || (getroot1(ant[getroot1(v)]) == getroot(ant[getroot1(u)]))))) {
                cout << "NO\n";
                continue;
            }

            cout << "YES\n";
            unions1(u, v);
        } else {
            if (getroot1(u) == getroot1(v)) {
                cout << "NO\n";
                continue;
            }

            ant1[getroot1(u)] = getroot1(v);
            ant1[getroot1(v)] = getroot1(u);
            cout << "YES\n";
            unions1(ant1[u], u);
            unions1(ant1[v], v);
        }
    }

    while (q--) {
        cin >> s >> ss;
        u = t[s];
        v = t[ss];
        if (getroot1(u) == getroot1(v)) {
            cout << "1\n";
        } else if (getroot2(ant[u]) == getroot2(v)) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
}
