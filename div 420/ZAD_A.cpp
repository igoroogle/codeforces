#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[53][53];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i, j, k, l,  s;
    bool f;
    cin >> n;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                continue;
            }

            f = 1;
            for (k = 0; k < n; ++k) {
                if (!f) {
                    break;
                }

                for (l = 0; l < n; ++l) {
                    if (a[i][k] + a[l][j] == a[i][j]) {
                        f = 0;
                        break;
                    }
                }
            }

            if (f) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
