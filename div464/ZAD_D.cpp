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
const ll INF = 1E18 + 3;
const ll DL = 31623;
int par[28], len[28];

int getroot(int u) {
    if (par[u] == -1) {
        return u;
    }

    par[u] = getroot(par[u]);
    return par[u];
}

void unions(int u, int v) {
    u = getroot(u);
    v = getroot(v);
    if (len[u] < len[v]) {
        par[u] = v;
    } else if (len[u] > len[v]) {
        par[v] = u;
    } else {
        par[u] = v;
        ++len[v];
    }
}

vector<pair<char, char>> ans;
int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 28; ++i) {
        par[i] = -1;
        len[i] = 0;
    }
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    for (int i = 0; i < n; ++i) {
        //cout << getroot(int(s[i] - 'a')) << ' ' << getroot(int(t[i] - 'a')) << endl;
        if (getroot(int(s[i] - 'a')) != getroot(int(t[i] - 'a'))) {
            unions(int(s[i] - 'a'), int(t[i] - 'a'));
            ans.pb(mp(s[i], t[i]));
        }
    }

    cout << ans.size() << endl;
    for (auto cur : ans) {
        cout << cur.x << ' ' << cur.y << '\n';
    }
}
