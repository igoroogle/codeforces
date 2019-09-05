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

bool is_mid(int y, int y1, int y2) {
    if ((min(y1, y2) <= y) && (max(y1, y2) >= y)) {
        return true;
    }

    return false;
}

void nx(int& j, int& v, int n) {
    j += v;
    if (j > n) {
        j -= 2;
        v = -1;
    } else if (j < 0) {
        j += 2;
        v = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, d, m, x, y;
    cin >> n >> d;
    cin >> m;

    while(m--) {
        int j1 = d, j2 = d, v1 = 1, v2 = -1;
        cin >> x >> y;
        for (int i = 0; i <= n; ++i) {
            if (x == i) {
                if (is_mid(y, j1, j2)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
                break;
            }
            nx(j1, v1, n);
            nx(j2, v2, n);
        }
    }
}
