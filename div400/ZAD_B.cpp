#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    ++n;
    if (n == 2) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    if (n == 3) {
        cout << 1 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    int f;
    cout << 2 << endl;
    for (i = 2; i <= n; ++i) {
        f = 1;
        for (j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                f = 2;
                break;
            }
        }

        cout << f << ' ';
    }
}
