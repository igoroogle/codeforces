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
    int n, a, b, as, bs;
    cin >> n >> a >> b;
    as = a;
    bs = b;
    string s;
    cin >> s;
    s = s + "*";
    int vl = 0, mn;
    for (int i = 0; i < n + 1; ++i) {

        if (max(a,b) == 0) {
            continue;
        }

        if (s[i]  == '.') {
            ++vl;
            continue;
        }

        mn = min(a, b);
        if (mn >= vl / 2) {
            a -= vl / 2;
            b -= vl / 2;
            vl %= 2;
        } else {
            a -= mn;
            b -= mn;
            vl -= (mn + mn);
        }

        if (max(a,b) == 0) {
            continue;
        }

        if (vl > 0) {
            if (a > b) {
                --a;
            } else {
                --b;
            }
        }
        vl = 0;
    }

    cout << as + bs - a - b << endl;
}
