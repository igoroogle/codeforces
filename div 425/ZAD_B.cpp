#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
string s, t;
bool vl[27];
int main() {
    ios_base::sync_with_stdio(0);
    int n, i, j, sz, m, ff, a, b;
    bool f;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; ++i) {
        vl[int(s[i] - 'a')] = true;
    }

    cin >> t;
    sz = t.length();
    cin >> m;
    while (m--) {
        cin >> s;
        n = s.length();
        ff = 0;
        a = 0;
        b = 0;
        for (i = 0; i < min(n, sz); ++i) {
            if ((s[i] == t[i]) || ((t[i] == '?') && (vl[s[i] - 'a']))) {
                ++a;
                if ((i == min(n, sz) - 1)) {
                    if ((i + 1 < sz) && (t[i + 1] == '*')) {
                        ++ff;
                    }
                }
            } else {
                if (t[i] == '*') {
                    ++ff;
                }
                break;
            }
        }

        i = n - 1;
        j = sz - 1;
        while (min(i, j) >= 0) {
            if ((s[i] == t[j]) || ((t[j] == '?') && (vl[s[i] - 'a']))) {
                ++b;
                if ((min(i, j) == 0) && (j - 1 >= 0) && (t[j - 1] == '*')) {
                    ++ff;
                }
            } else {
                if (t[j] == '*') {
                    ++ff;
                }
                break;
            }
            --i;
            --j;
        }

        f = true;
        for (i = a; i  < n - b; ++i) {
            if (vl[s[i] - 'a']) {
                f = false;
                break;
            }
        }

        if (((ff == 0) && (n == a)) || ((ff == 2) && (f))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}
