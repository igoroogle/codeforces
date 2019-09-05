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

int main() {
    //ios_base::sync_with_stdio(0);
    for(;;) {
        string s;
        cin >> s;
        if (s == "end") {
            break;
        }

        int k = 0;
        char c;
        for(;;) {
            cout << "? " << (1 << k) << ' ' << (1 << (k + 1)) << endl;
            cin >> c;
            if (c == 'x') {
                break;
            }
            ++k;
        }

        if (k == 0) {
            cout << "? 2 1" << endl;
            cin >> c;
            if (c == 'y') {
                cout << "! 2" << endl;
            } else {
                cout << "! 1" << endl;
            }
            continue;
        }

        int x = (1 << k);
        int l = 1, r = x;
        while (l < r) {
            int m = (l + r) >> 1;
            cout << "? " << x << ' ' << x + m << endl;
            cin >> c;
            if (c == 'y') {
                l = m + 1;
            } else {
                r = m;
            }
        }

        cout << "! " << x + l << endl;
    }
}
