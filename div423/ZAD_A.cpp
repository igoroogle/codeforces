#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, a, b, c = 0, x, ans = 0;
    cin >> n >> a >> b;
    while (n--) {
        cin >> x;
        if (x == 1) {
            if (a > 0) {
                --a;
            } else if (b > 0) {
                --b;
                ++c;
            } else if (c > 0) {
                --c;
            } else {
                ++ans;
            }
        } else {
            if (b > 0) {
                --b;
            } else {
                ans += 2;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
