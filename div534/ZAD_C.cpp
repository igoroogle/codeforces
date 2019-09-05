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
vector<pair<int, int>> gor = {{1, 1}, {2, 1}, {3, 1}, {4, 1}};
vector<pair<int, int>> ver = {{1, 3}, {3, 3}};

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int gv = 0, vr = 0;
    for (auto c : s) {
        if (c == '1') {
            cout << gor[gv].x << ' ' << gor[gv].y << '\n';
            gv = (gv + 1) % 4;
        } else {
            cout << ver[vr].x << ' ' << ver[vr].y << '\n';
            vr = (vr + 1) % 2;
        }
    }


}
