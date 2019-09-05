#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
ll a[1003], b[1003], c[1003];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, k1, k2, k;
    cin >> n >> k1 >> k2;
    k = k1 + k2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        c[i] = abs(a[i] - b[i]);
    }

    while (k > 0) {
        int ind = 0;
        for (int i = 1; i < n; ++i) {
            if (c[i] > c[ind]) {
                ind = i;
            }
        }

        if (c[ind] == 0) {
            c[ind] = 1;
        } else {
            --c[ind];
        }
        --k;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += sqr(c[i]);
    }

    cout << ans << endl;
}
