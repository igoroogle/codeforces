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

int main() {
    ios_base::sync_with_stdio(0);
    int x = 0, y = 0, n, xn, yn, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    bool f;
    for (int i = 0; i < n; ++i) {
        xn = x;
        yn = y;
        if (s[i] == 'U') {
            ++yn;
        } else {
            ++xn;
        }

        if (xn != yn) {
            if ((x == 0) && (y == 0)) {
                f = (xn < yn);
            } else {
                if (xn < yn) {
                    if (!f) {
                        ++ans;
                        f = true;
                    }
                } else {
                    if (f) {
                        ++ans;
                        f = false;
                    }
                }
            }
        }
        x = xn;
        y = yn;
    }
    cout << ans << endl;
}
