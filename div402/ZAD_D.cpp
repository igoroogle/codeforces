#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
string t, p;
int n, m;
bool use[200010];
int a[200010];
bool prov(int x) {
    if (n - x < m) {
        return false;
    }

    int i, j;
    for (i = 0; i < n; ++i) {
        use[i] = 1;
    }

    for (i = 1; i <= x; ++i) {
        use[a[i - 1]] = 0;
    }

    i = 0;
    j = 0;
    while ((i < n) && (j < m)) {
        if (use[i]) {
            if (t[i] == p[j]) {
                ++j;
            }
        }
        ++i;
    }

    return (j == m);
}

int main() {
    ios_base::sync_with_stdio(0);
    getline(cin, t);
    getline(cin, p);
    n = t.length(), m = p.length();
    int l = 0;
    int r = n + 1, mm, i;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    while (l < r) {
        mm = (l + r) >> 1;
        if (prov(mm)) {
            l = mm + 1;
        } else {
            r = mm;
        }
    }

    cout << l - 1 << endl;
}
