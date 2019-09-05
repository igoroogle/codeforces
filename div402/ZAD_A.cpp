#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int a[7], b[7];
int main() {
    int n, x, i, a1 = 0, b1 = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x;
        ++a[x];
    }

    for (i = 0; i < n; ++i) {
        cin >> x;
        ++b[x];
    }

    for (i = 0; i < 7; ++i) {
        if (abs(a[i] - b[i]) % 2) {
            cout << -1 << endl;
            return 0;
        }

        if (a[i] > b[i]) {
            a1 += a[i] - b[i];
        } else if (a[i] < b[i]) {
            b1 += b[i] - a[i];
        }
    }

    if (a1 != b1) {
        cout << -1 << endl;
    } else {
        cout << a1 / 2 << endl;
    }
}
