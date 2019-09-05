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
vector<int> zer, ed;
int prevs[200010];
vector<vector<int>> ans;
vector<int> val;
int main() {
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        prevs[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (!ed.empty()) {
                zer.pb(i);
                prevs[i] = ed.back();
                ed.pop_back();
            } else {
                zer.pb(i);
            }
        } else {
            if (!zer.empty()) {
                ed.pb(i);
                prevs[i] = zer.back();
                zer.pop_back();
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (!ed.empty()) {
        cout << -1 << endl;
        return 0;
    }

    for (auto cur : zer) {
        int vl = cur;
        val.clear();
        while (vl != -1) {
            val.pb(vl);
            vl = prevs[vl];
        }
        reverse(val.begin(), val.end());
        ans.pb(val);
    }

    cout << ans.size() << endl;
    for (auto cur : ans) {
        cout << cur.size();
        for (auto cur2 : cur) {
            cout << ' ' << cur2 + 1;
        }
        cout << '\n';
    }
}
