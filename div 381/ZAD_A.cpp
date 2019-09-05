#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
int main() {
    ll n, a, b, c, j, k, d, sm, st, kans, ans = 2E18, i;
    cin >> n >> a >> b >> c;
    if (n % 4 == 0) {
        cout << 0 << endl;
        return 0;
    }

    st = 3;
    for (d = 1; d < 9; ++d) {
        for (i = 0; i < st; ++i) {
            sm = n;
            kans = 0;
            k = i;
            for (j = 0; j < d; ++j) {
                if (k % 3 == 0) {
                    sm += 1;
                    kans += a;
                } else if (k % 3 == 1) {
                    sm += 2;
                    kans += b;
                } else if (k % 3 == 2) {
                    sm += 3;
                    kans += c;
                }

                k /= 3;
            }

            if (sm % 4 == 0)
                ans = min(ans, kans);
        }

        st *= 3;
    }

    cout << ans << endl;
}
