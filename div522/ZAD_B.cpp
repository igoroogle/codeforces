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
char a[103][103];
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = 0, m = 0;
    while (n * 20 < int(s.length())) {
        ++n;
    }

    while (m * n < int(s.length())) {
        ++m;
    }

    int ind = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = '*';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            a[i][j] = s[ind];
            ++ind;
        }
        if (int(s.length()) - ind == (n - i - 1) * m + 1) {
            a[i][m - 1] = s[ind];
            ++ind;
        }
    }


    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}
