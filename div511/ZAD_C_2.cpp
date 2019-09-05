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
const int DL = 15000007;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int a[300010], vl[DL], pr[DL], vans[DL];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int gd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        gd = gcd(a[i], gd);
    }

    bool f = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != gd) {
            f = false;
            break;
        }
    }

    if (f) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 2; i < DL; ++i) {
        if (pr[i] != 0) {
            continue;
        }

        for (int j = i; j < DL; j += i) {
            if (pr[j] == 0) {
                pr[j] = i;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ++vl[a[i]];
    }

    int ans = 0;
    for (int i = DL - 1; i > gd; --i) {
        vans[pr[i]] += vl[i];
    }

    for (int i = DL - 1; i > gd; --i) {
        ans = max(ans, vl[i]);
        ans = max(ans, vans[i]);
        if (pr[i] != i) {
            vl[i / pr[i]] += vl[i];
        }
    }

    cout << n - ans << '\n';
}
