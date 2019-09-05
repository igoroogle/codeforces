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
int a[100010], b[100010], sm[5];
int main() {
    ios_base::sync_with_stdio(0);
    int n, kl = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    if (a[0] + 1 >= a[n - 1]) {
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        ++sm[a[i] - a[0]];
        sum += a[i] - a[0];
    }

    int va = sm[0], vb = sm[1], vc = sm[2], sv = n;
    int ua, ub, uc, uv;
    for (int i = 0; i <= n; ++i) {
        uc = i;
        if ((sum - i - i) >= 0) {
            ub = sum - i - i;
            if (n - ub - uc < 0) {
                continue;
            }
            ua = n - ub - uc;

        } else {
            continue;
        }
        if ((ub + uc + uc != sum) || (ua + ub + uc != n)) {
            continue;
        }

        uv = min(ua, sm[0]) + min(ub, sm[1]) + min(uc, sm[2]);
        if (uv < sv) {
            va = ua;
            vb = ub;
            vc = uc;
            sv = uv;
        }
    }
    cout << sv << endl;
    for (int i = 0; i < va; ++i) {
        cout << a[0] << ' ';
    }

    for (int i = 0; i < vb; ++i) {
        cout << a[0] + 1 << ' ';
    }

    for (int i = 0; i < vc; ++i) {
        cout << a[0] + 2 << ' ';
    }

    return 0;
}
