#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DLV = 30010;
const int DL = 10001;
int bits[DLV], kol[DL];
int main() {
    int i, j, val, n, k;
    ll ans = 0;
    for (i = 0; i < DLV; ++i) {
        j = i;
        val = 0;
        while (j > 0) {
            if (j & 1) {
                ++val;
            }
            j >>= 1;
        }
        bits[i] = val;
    }

    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        scanf("%d", &val);
        ++kol[val];
    }

    for (i = 0; i < DL; ++i) {
        for (j = i + 1; j < DL; ++j) {
            if ((bits[i] + bits[j] - bits[i & j] - bits[i & j] == k)) {
                ans += ll(kol[i]) * ll(kol[j]);
            }
        }

        if (k == 0) {
            ans += (ll(kol[i] - 1) * ll(kol[i])) >> ll(1);
        }
    }

    cout << ans << endl;
}
