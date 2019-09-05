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
int a[503][503], b[503][503];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                ++sum;
            }
        }

        if (sum % 2) {
            cout << "No\n";
            return 0;
        }
    }

    for (int j = 0; j < m; ++j) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] != b[i][j]) {
                ++sum;
            }
        }

        if (sum % 2) {
            cout << "No\n";
            return 0;
        }
    }


    cout << "Yes\n";
}
