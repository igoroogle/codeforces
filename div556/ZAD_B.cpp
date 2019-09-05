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
typedef pair<int, int> pii;
const int INF = 1E9 + 7;
char a[55][55];

void check(int i, int j, int n) {
    if ((i < 0) || (j < 0) || (i >= n) || (j >= n) || (a[i][j] == '#')) {
        cout << "NO\n";
        exit(0);
    }
    a[i][j] = '#';
}

void do_it(int i, int j, int n) {
    if (a[i][j] == '#') {
        return;
    }
    check(i, j, n);
    check(i + 1, j - 1, n);
    check(i + 1, j, n);
    check(i + 1, j + 1, n);
    check(i + 2, j, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            do_it(i, j, n);
        }
    }

    cout << "YES\n";
}
