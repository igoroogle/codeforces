#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    list<pair<int, int>> vl;
    int ans = 0;
    string s;
    cin >> s;
    for (size_t i = 0; i < s.length(); ++i) {

        if ((i == 0) || (vl.back().y != int(s[i] - 'a'))) {
            vl.push_back(mp(1, int(s[i] - 'a')));
        } else {
            ++vl.back().x;
        }
    }

    /*for (auto cur : vl) {
        cout << cur.x << ' ' << cur.y << endl;
    }*/
    while (vl.size() > 1) {
        ++ans;
        auto cur = vl.begin();
        auto en = vl.end();
        --en;
        while (cur != vl.end()) {
            if (cur != vl.begin()) {
                --(cur->x);
            }

            if (cur != en) {
                --(cur->x);
            }
            cur->x = max(cur->x, 0);
            ++cur;
        }

        cur = vl.begin();
        auto nx = cur;
        while (cur != vl.end()) {
            nx = cur;
            ++nx;
            if (cur->x == 0) {
                vl.erase(cur);
            }
            cur = nx;
        }

        cur = vl.begin();
        nx = cur;
        if (nx != vl.end()) {
            ++nx;
        }

        while (nx != vl.end()) {
            if (cur->y == nx->y) {
                cur->x += nx->x;
                vl.erase(nx);
                nx = cur;
                ++nx;
                continue;
            }
            cur = nx;
            ++nx;
        }
    }

    //cout << endl;
    /*for (auto cur : vl) {
        cout << cur.x << ' ' << cur.y << endl;
    }*/
    cout << ans << endl;
}
