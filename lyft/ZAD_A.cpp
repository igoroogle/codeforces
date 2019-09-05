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
bool a[1003][1003], b[1003][1003];

bool check(int x, int y, int n) {
    if ((x <= 0) || (y <= 0) || (x > n) || (y > n) || (a[x][y])) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, ax, ay, bx, by, cx, cy;
    cin >> n >> ax >> ay >> bx >> by >>  cx >> cy;
    for (int i = 1; i <= n; ++i) {
        a[i][ay] = true;
        a[ax][i] = true;

        if ((ax + i <= n) && (ay + i <= n)) {
            a[ax + i][ay + i] = true;
        }

        if ((ax - i > 0) && (ay - i > 0)) {
            a[ax - i][ay - i] = true;
        }

        if ((ax + i <= n) && (ay - i > 0)) {
            a[ax + i][ay - i] = true;
        }

        if ((ax - i > 0) && (ay + i <= n)) {
            a[ax - i][ay + i] = true;
        }
    }

    queue<pair<int, int>> q;
    q.push(mp(bx, by));
    while (!q.empty()) {
        auto val = q.front();
        if (val == mp(cx, cy)) {
            cout << "YES\n";
            return 0;
        }
        q.pop();

        if (check(val.x + 1, val.y, n)) {
            q.push(mp(val.x + 1, val.y));
            a[q.back().x][q.back().y] = true;
        }

        if (check(val.x - 1, val.y, n)) {
            q.push(mp(val.x - 1, val.y));
            a[q.back().x][q.back().y] = true;
        }

        if (check(val.x, val.y - 1, n)) {
            q.push(mp(val.x, val.y - 1));
            a[q.back().x][q.back().y] = true;
        }

        if (check(val.x, val.y + 1, n)) {
            q.push(mp(val.x, val.y + 1));
            a[q.back().x][q.back().y] = true;
        }

        if (check(val.x + 1, val.y + 1, n)) {
            q.push(mp(val.x + 1, val.y + 1));
            a[q.back().x][q.back().y] = true;
        }

        if (check(val.x - 1, val.y + 1, n)) {
            q.push(mp(val.x - 1, val.y + 1));
            a[q.back().x][q.back().y] = true;
        }

        if (check(val.x + 1, val.y - 1, n)) {
            q.push(mp(val.x + 1, val.y - 1));
            a[q.back().x][q.back().y] = true;
        }

        if (check(val.x - 1, val.y - 1, n)) {
            q.push(mp(val.x - 1, val.y - 1));
            a[q.back().x][q.back().y] = true;
        }
    }

    cout << "NO\n";
}
