#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> vl[4];

int a[5010], b[5010];
vector<int> an;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        b[i] = c - '0';
    }

    for (int i = 0; i < n; ++i) {
        int x = a[i] << 1;
        x ^= b[i];
        vl[x].pb(i);
    }

    if (int(vl[1].size()) % 2) {
        if (max(vl[0].size(), vl[3].size()) == 0) {
            cout << -1 << '\n';
            return 0;
        }

        if (vl[0].size() > vl[3].size()) {
            an.pb(vl[1].back());
            vl[1].pop_back();
            vl[0].pop_back();
        } else {
            an.pb(vl[3].back());
            vl[1].pop_back();
            vl[3].pop_back();
        }
    }

    if (int(vl[2].size()) % 2) {
        if (max(vl[0].size(), vl[3].size()) == 0) {
            cout << -1 << '\n';
            return 0;
        }

        if (vl[0].size() > vl[3].size()) {
            an.pb(vl[0].back());
            vl[2].pop_back();
            vl[0].pop_back();
        } else {
            an.pb(vl[2].back());
            vl[2].pop_back();
            vl[3].pop_back();
        }
    }

    int m = min(vl[1].size(), vl[2].size());

    for (int i = 0; i < m; ++i) {
        an.pb(vl[1][i]);
    }

    int t, ot, vt;
    if (vl[1].size() < vl[2].size()) {
        t = 2;
        ot = 3;
        vt = 0;
    } else {
        t = 1;
        ot = 0;
        vt = 3;
    }


    while (m < int(vl[t].size())) {
        if ((int(vl[ot].size()) > 0) && (int(vl[ot].size()) % 2)) {
            vl[ot].pop_back();
            an.pb(vl[t][m]);
        } else if ((int(vl[vt].size()) > 0) && (int(vl[vt].size()) % 2)) {
            an.pb(vl[vt].back());
            vl[vt].pop_back();
        } else if (vl[ot].size() > vl[vt].size()) {
            an.pb(vl[t][m]);
            vl[ot].pop_back();
        } else {
            if (int(vl[vt].size()) == 0) {
                cout << -1 << '\n';
                return 0;
            }
            an.pb(vl[vt].back());
            vl[vt].pop_back();
        }
        ++m;
    }

    if ((int(vl[0].size()) % 2) || ((int(vl[3].size()) % 2))) {
        cout << -1 << '\n';
        return 0;
    }

    m = vl[0].size();
    for (int i = 0; i < m / 2; ++i) {
        an.pb(vl[0][i]);
    }

    m = vl[3].size();
    for (int i = 0; i < m / 2; ++i) {
        an.pb(vl[3][i]);
    }

    her:
    for (auto cur : an) {
        cout << cur + 1 << ' ';
    }
}
