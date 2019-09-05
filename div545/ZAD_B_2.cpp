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

    int m = min(vl[1].size(), vl[2].size());
    int tm = max(vl[1].size(), vl[2].size());
    int ani = -1, anj = -1, ank = -1;

    for (int i = 0; i <= m; ++i) {
        if (ani != -1) {
            break;
        }

        int vls = (m - i) * 2 + tm - m;
        int tvl = min(vls, int(vl[0].size()));
        for (int j = 0; j <= tvl; ++j) {
            if (((int(vl[0].size()) - j) % 2 == 0)
                && ((int(vl[3].size()) - vls + j) >= 0)
                && ((int(vl[3].size()) - vls + j) % 2 == 0)) {
                    ani = i;
                    anj = j;
                    ank = vls - j;
                    break;
                }
        }
    }

    if (ani == -1) {
        cout << -1 << '\n';
        return 0;
    }
    //cout << ani << ' ' << anj << ' ' << ank << endl;

    for (int i = 0; i < ani; ++i) {
        an.pb(vl[1].back());
        vl[1].pop_back();
        vl[2].pop_back();
    }

    for (int i = 0; i < anj; ++i) {
        if (!vl[1].empty()) {
            an.pb(vl[1].back());
            vl[0].pop_back();
            vl[1].pop_back();
        } else {
            an.pb(vl[0].back());
            vl[0].pop_back();
            vl[2].pop_back();
        }
    }

    for (int i = 0; i < ank; ++i) {
        if (!vl[1].empty()) {
            an.pb(vl[3].back());
            vl[3].pop_back();
            vl[1].pop_back();
        } else {
            an.pb(vl[2].back());
            vl[3].pop_back();
            vl[2].pop_back();
        }
    }

    for (int i = 0; i < int(vl[0].size()) / 2; ++i) {
        an.pb(vl[0][i]);
    }

    for (int i = 0; i < int(vl[3].size()) / 2; ++i) {
        an.pb(vl[3][i]);
    }

    for (auto cur : an) {
        cout << cur + 1 << ' ';
    }
}
