#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef long double ld;
using namespace std;
int a[1000100], n, k, i, m;
bool prov(ll x) {
    int i;
    ll kl, tt;
    if (x == 0)
        return true;
    ll j = 0;
    for (i = 0; i < n; ++i) {
        if (a[i] < x) {
            continue;
        }

        kl = 1;
        tt = a[i];
        while ((tt / ll(2) >= x) && (j + kl < k)) {
            kl *= ll(2);
            tt /= ll(2);
        }

        j += kl;
    }
    if (j >= k)
        return true;
    return false;
}


int main() {
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    ll l = 0, r = 1E14;
    while (l < r) {
        m = (l + r) / ll(2);
        if (prov(m)) {
            l = m + ll(1);
        } else {
            r = m;
        }
    }
    if (l - ll(1) == ll(0)) {
        cout << -1 << endl;
        return 0;
    }
    cout << l - ll(1) << endl;
}
