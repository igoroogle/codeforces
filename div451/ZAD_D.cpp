#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 2000003;
ll a[DL], sm[DL];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, k, x, ans = 0;
    cin >> n >> m >> k;
    while (n--) {
        cin >> x;
        ++a[x];
    }

    for (int i = 1; i < DL; ++i) {
        sm[i] = sm[i - 1] + a[i];

        if (sm[i] - sm[max(i - m, ll(0))] >= k) {
            --a[i];
            --sm[i];
            ++ans;
        }
    }
    cout << ans << endl;
}
