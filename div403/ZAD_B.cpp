#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1E-9;
int x[100010], v[100010], n;
bool prov(ld t) {
    int i = 0;
    ld l = -2E9, r = 2E9, l1, r1;
    for (i = 0; i < n; ++i) {
        l1 = ld(x[i]) - ld(v[i]) * t;
        r1 = ld(x[i]) + ld(v[i]) * t;
        l = max(l, l1);
        r = min(r, r1);
        if (l > r) {
            return true;
        }

    }
    return false;
}

int main() {
    int i, j;
    ld l = 0.0, r = 2E9, m;
    cin >> n;
    for (i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    while (abs(l - r) > EPS) {
        m = (l + r) / ld(2);
        if (prov(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << fixed << setprecision(7) << (l + r) / ld(2) << endl;
}
