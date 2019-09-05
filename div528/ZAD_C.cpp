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
const int LEN = 1002;

bool use[LEN][LEN];
vector<pair<int, int>> a, ans;

void getX(pair<int, int> p1, pair<int, int> p2) {
    int i = p1.x;
    if (!use[p1.x][p1.y]) {
        use[p1.x][p1.y] = true;
        a.pb(p1);
    }

    while (i != p2.x) {
        if (i > p2.x) {
            --i;
        } else {
            ++i;
        }

        if (!use[i][p1.y]) {
            use[i][p1.y] = true;
            a.em(i, p1.y);
        }
    }
}

void getY(pair<int, int> p1, pair<int, int> p2) {
    int i = p1.y;
    if (!use[p1.x][p1.y]) {
        use[p1.x][p1.y] = true;
        a.pb(p1);
    }

    while (i != p2.y) {
        if (i > p2.y) {
            --i;
        } else {
            ++i;
        }

        if (!use[p1.x][i]) {
            use[p1.x][i] = true;
            a.em(p1.x, i);
        }
    }
}

void getWay(pair<int, int> p1, pair<int, int> p2, int t) {
    if (t == 0) {
        getX(p1, p2);
        getY(mp(p2.x, p1.y), p2);
    } else {
        getY(p1, p2);
        getX(mp(p1.x, p2.y), p2);
    }
}

void getAns(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, int t1, int t2) {
    a.clear();
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            use[i][j] = false;
        }
    }

    getWay(p1, p2, t1);
    getWay(p2, p3, t2);
    if ((ans.empty()) || (a.size() < ans.size())) {
        ans = a;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    pair<int, int> p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            getAns(p1, p2, p3, i, j);
            getAns(p1, p3, p2, i, j);
            getAns(p2, p1, p3, i, j);
            getAns(p2, p3, p1, i, j);
            getAns(p3, p1, p2, i, j);
            getAns(p3, p2, p1, i, j);
        }
    }

    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur.x << ' ' << cur.y << '\n';
    }
}

/*
0 0
0 4
3 2
*/
