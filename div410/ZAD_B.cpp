#include<bits/stdc++.h>
using namespace std;
string s, ss;
map<string, int> t;
map<string, bool> v, g;
int main() {
    ios_base::sync_with_stdio(0);
    int n, i, j, vl, ans = 1E9;
    cin >> n;
    n--;
    cin >> s;
    vl = 0;
    for (i = 0; i < s.length(); ++i) {
        v[s] = true;
        g[s] = true;
        t[s] += vl;
        ss = s.substr(0, 1);
        s.erase(0, 1);
        s += ss;
        if (v[s]) {
            break;
        }
        ++vl;
    }

    while (n--) {
        cin >> s;
        vl = 0;
        v.clear();
        for (i = 0; i < s.length(); ++i) {
            v[s] = true;
            if (!g[s]) {
                cout << -1 << endl;
                return 0;
            }

            t[s] += vl;
            ss = s.substr(0, 1);
            s.erase(0, 1);
            s += ss;
            if (v[s]) {
                break;
            }
            ++vl;
        }
    }

    v.clear();
    for (i = 0; i < s.length(); ++i) {
        v[s] = true;
        ans = min(ans, t[s]);
        ss = s.substr(0, 1);
        s.erase(0, 1);
        s += ss;
        if (v[s]) {
            break;
        }
        ++vl;
    }

    cout << ans << endl;
    return 0;
}
