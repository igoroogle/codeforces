#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll k = 1, to = 1, ans = 1;
    while (k < 30) {
        if (n % to == 0) {
            ans = max(ans, to);
        }
        ++k;
        to = ((ll(1) << k) - ll(1)) * (ll(1) << ll(k - 1));
    }

    cout << ans << endl;
    return 0;
}
