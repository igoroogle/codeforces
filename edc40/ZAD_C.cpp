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

//int a[200010];

ll getVal(ll x, ll y, ll i, ll j) {
    if ((i < 1) || (j < 1) || (i > x) || (j > y)) {
        //cout << "WTF\n";
        //cout << i << ' ' << j << endl;
        return ll(-1);
    }
    //cout << "UTF\n";
        //cout << i << ' ' << j << ' ' << x << ' ' << y << endl;
    //cout << y * ll(i - 1) + j << endl;
    return y * ll(i - 1) + j;
}

bool check(ll x, ll y, ll& i, ll& j, ll val) {
    if ((getVal(x, y, i - 1, j) == val)) {
        i = i - 1;
        return true;
    }

    if ((getVal(x, y, i + 1, j) == val)) {
        i = i + 1;
        return true;
    }

    if ((getVal(x, y, i, j - 1) == val)) {
        j = j - 1;
        return true;
    }

    if ((getVal(x, y, i, j + 1) == val)) {
        j = j + 1;
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    ll n, x = 1E9, y = 1, val, xx = 1, yy = 1, oldval;
    bool f = false;
    cin >> n;
    cin >> oldval;
    ll ml = oldval;
    ll mr = oldval;
    while (n--) {
        cin >> val;
        if (abs(oldval - val) == 1) {
            oldval = val;
            ml = min(val, ml);
            mx = max(val, mr);
        } else {
            if (val == oldval) {
                cout << "NO\n";
                return 0;
            }

            if (val > oldval) {
                if (val <= mr) {
                    cout << "NO\n";
                    return 0;
                }

                int rz = val - oldval;
                int cr = oldval / rz
                cr = oldval - cr * rz;

            }
        }
    }
    while(n--) {
        /*if (!f) {
            if (yy - 1 == val) {
                --yy;
                continue;
            }
            else if (yy + 1 != val) {
                f = true;
                if (val - yy < y) {
                    cout << "NO\n";
                    return 0;
                }
                y = val - yy;
            } else {
                ++yy;
                y = max(yy, y);
                continue;
            }
        }*/

        //cout << i << endl;
        //cout << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
        if (check(x, y, xx, yy, val)) {
            continue;
        } else {
            //cout << i << endl;
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    cout << x << ' ' << y << endl;
}
