#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_beck
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
int a[1010];
int main() {
    int n, m, c;
    cin >> n >> m >> c;
    int l1 = 0, r1 = -1, l2 = n, r2 = n - 1, p;
    while (m--) {
        cin >> p;
        if (p <= c / 2) {
            for (int i = 0; i < n; ++i) {
                if ((a[i] == 0) || (a[i] > p)) {
                    cout << i + 1 << endl;
                    fflush(stdout);
                    a[i] = p;
                    r1 = max(r1, i);
                    break;
                }
            }
        } else {
            for (int i = n - 1; i >= 0; --i) {
                if (a[i] < p) {
                    cout << i + 1 << endl;
                    fflush(stdout);
                    a[i] = p;
                    l2 = min(l2, i);
                    break;
                }
            }
        }
        if (r1 - l1 + 1 + r2 - l2 + 1 == n) {
            return 0;
        }
    }

}
