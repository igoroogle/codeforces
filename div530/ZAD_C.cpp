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
int code[210], vl[3];
char a[210];

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int m = 0;
    for (int i = 0; i < int(s.length()); ++i) {
        if (s[i] == '?') {
            code[m - 1] = 0;
            continue;
        } else if (s[i] == '*') {
            code[m - 1] = 1;
            continue;
        } else {
            a[m++] = s[i];
            code[m - 1] = 2;
            continue;
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < m; ++i) {
        ++vl[code[i]];
    }

    if ((vl[2] > k) || ((vl[1] == 0) && (vl[0] + vl[2] < k))) {
        cout << "Impossible\n";
        return 0;
    }

    k -= vl[2];
    for (int i = 0; i < m; ++i) {
        if (code[i] == 2) {
            cout << a[i];
            continue;
        }

        if (k == 0) {
            continue;
        }

        if (code[i] == 0) {
            cout << a[i];
            --k;
            continue;
        }

        while (k > 0) {
            cout << a[i];
            --k;
        }
    }

    cout << '\n';
    return 0;
}
