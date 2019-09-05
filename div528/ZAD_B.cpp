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

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll ans = -1;
    for (ll i = 1; i < k; ++i) {
        if (n % i == 0) {
            int j = (n / i) * k + i;
            //cout << j << ' ' << j / k << ' ' << j % k << endl;
            if ((j / k == n / i) && (j % k == i)) {
                if ((ans == -1) || (ans > j)) {
                    ans = j;
                }
            }
        }
    }

    cout << ans << '\n';
}
