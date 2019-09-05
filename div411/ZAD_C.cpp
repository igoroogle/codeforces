#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
int main() {
    //ios_base::sync_with_stdio(0);
    ll i, n, l, r, ans = 0;
    cin >> n;
    l = 1;
    r = n;
    while (l < r) {
        ans += (l + r) % (n + 1);
        ++l;

        if (l < r) {
            ans += (l + r) % (n + 1);
            --r;
        }
    }

    cout << ans << endl;
    return 0;
}
