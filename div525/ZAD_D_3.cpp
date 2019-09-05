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
const int BVAL = 30;

int main() {
    int c = 0, d = 0;
    int tp;
    cout << "? 0 0" << endl;
    cin >> tp;

    for (int i = BVAL - 1; i >= 0; --i) {
        int t1, t2;
        cout << "? " << c << ' ' << (d ^ (1 << i)) << endl;
        cin >> t1;

        cout << "? " << (c ^ (1 << i)) << ' ' << d << endl;
        cin >> t2;

        if (t1 > t2) {
            c ^= (1 << i);
            d ^= (1 << i);
        } else if (t1 == t2) {
            if (tp == -1) {
                d ^= (1 << i);
            } else {
                c ^= (1 << i);
            }
            tp = t1;
        }
    }


    cout << "! " << c << ' ' << d << endl;
}
