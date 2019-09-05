#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    ll x, y;
    cin >> x >> y;
    if (x == y) {
        cout << "=\n";
        return 0;
    }

    if (x == 1) {
        cout << "<\n";
        return 0;
    }

    if (y == 1) {
        cout << ">\n";
        return 0;
    }

    if (max(x, y) <= 11) {
        ll x1 = 1;
        ll y1 = 1;
        for (int i = 1; i <= y; ++i) {
            x1 *= x;
        }

        for (int i = 1; i <= x; ++i) {
            y1 *= y;
        }

        if (x1 < y1) {
            cout << "<\n";
        } else if (x1 > y1) {
            cout << ">\n";
        } else {
            cout << "=\n";
        }
        return 0;
    }

    if (x < y) {
        cout << ">\n";
    } else {
        cout << "<\n";
    }

}
