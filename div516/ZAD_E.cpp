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
typedef unsigned int uni;
const ll DL = 1E9;

int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll l = 0, r = 2 * DL;
    string s, t;
    --n;
    cout << "0 0" << endl;
    fflush(stdout);
    cin >> s;

    ll m;
    while ((l + 3 <= r) && (n > 0)) {
        //cout << l << ' ' << r << endl;
        m = (l + r) >> ll(1);
        if (m >= DL) {
            cout << m - DL << ' ' << DL << endl;
        } else {
            cout << "0 " << m << endl;
        }
        fflush(stdout);
        cin >> t;
        if (s == t) {
            l = m;
        } else {
            r = m;
        }
        --n;
    }

    ll x, y;
    m = (l + r) >> uni(1);
    if (m >= DL) {
        x = m - DL;
        y = DL;
    } else {
        x = 0;
        y = m;
    }


    if (n == 0) {
        cout << x << ' ' << y << " 1 0" << endl;
        fflush(stdout);
        return 0;
    }

    l = 0;
    r = 2 * DL;
    while (n--) {
        m = (l + r) >> uni(1);
        if (m >= DL) {
            cout << DL << ' ' << m - DL << endl;
        } else {
            cout << m << " 0" << endl;
        }
        fflush(stdout);

        cin >> t;
        if (s == t) {
            l = m;
        } else {
            r = m;
        }
    }

    m = (l + r) >> uni(1);
    if (m >= DL) {
        cout << DL << ' ' << m - DL << ' ';
    } else {
        cout << m << " 0" << ' ';
    }

    cout << x << ' ' << y << endl;
    fflush(stdout);
}
