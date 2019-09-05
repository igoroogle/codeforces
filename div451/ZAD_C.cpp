#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    /*vector<int> a = {1, 2, 3};
    cout << a.size();
    a.erase(a.begin() + 1);
    cout << a.size() << endl;*/
    ios_base::sync_with_stdio(0);
    map<string, int> vl;
    int n, m, ind, f, l;
    cin >> n;
    vector<string> name;
    vector<vector<string>> ans(n);
    string s, nm;
    for (int i = 0; i < n; ++i) {
        cin >> nm;
        if (vl[nm]) {
            ind = vl[nm] - 1;
        } else {
            ind = name.size();
            name.pb(nm);
            vl[nm] = name.size();
        }
        cin >> m;
        while (m--) {
            cin >> s;
            ans[ind].pb(s);
        }
    }

    bool fl;
    int i, j;
    for (int k = 0; k < name.size(); ++k) {
        i = 0;
        while (i < ans[k].size()) {
            fl = false;
            for (int j = 0; j < i; ++j) {
                f = ans[k][i].size() - 1;
                l = ans[k][j].size() - 1;
                fl = true;
                while (min(f, l) >= 0) {
                    if (ans[k][i][f] != ans[k][j][l]) {
                        fl = false;
                        break;
                    }
                    --f;
                    --l;

                }
                if (fl) {
                    if (f >= 0) {
                        swap(ans[k][i], ans[k][j]);
                    }
                    ans[k].erase(ans[k].begin() + i);
                    break;
                }
            }
            if (fl) {
                continue;
            }
            ++i;
        }
    }
    cout << name.size() << '\n';
    for (size_t i = 0; i < name.size(); ++i) {
        cout << name[i] << ' ' << ans[i].size();
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << ' ' << ans[i][j];
        }
        cout << '\n';
    }
}
