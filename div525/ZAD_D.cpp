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

void printVal(int x) {
    for (int i = BVAL - 1; i >= 0; --i) {
        if ((1 << i) & x) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}

int main() {
    //ios_base::sync_with_stdio(0);
    int a, b, c = 0, d = 0;
    int t;
    cout << "? 0 0" << endl;
    cin >> t;
    for (int i = BVAL - 1; i >= 0; --i) {
        if (t == 0) {
            break;
        } else if (t == -1) {
            cout << "? " << (c ^ (1 << i)) << ' ' << (d ^ (1 << i)) << endl;
            /*fflush(stdout);
            printVal((c ^ (1 << i)));
            printVal(d);*/
            cin >> t;
            if (t < 0) {
                continue;
            } else {
                c ^= (1 << i);
                d ^= (1 << i);
            }
        } else {
            cout << "? " << (c ^ (1 << i)) << ' ' << (d ^ (1 << i)) << endl;
            /*fflush(stdout);
            printVal((c ^ (1 << i)));
            printVal(d);*/
            cin >> t;
            if (t > 0) {
                continue;
            } else {
                c ^= (1 << i);
                d ^= (1 << i);
            }
        }
    }

    int add = (c ^ d);
    b = 0;
    t = 0;

    /*cout << add << endl;
    cout << "hren" << endl;*/
    for (int i = BVAL - 1; i >= 0; --i) {
        cout << "? " << add << ' ' << (b ^ (1 << i)) << endl;
        /*fflush(stdout);
        printVal(add);
        printVal(b ^ (1 << i));*/
        cin >> t;
        if (t == 1) {
            b ^= (1 << i);
            add ^= (1 << i);
        }
    }

    a = b ^ d ^ c;
    cout << "! " << a << ' ' << b << endl;
    fflush(stdout);
}
