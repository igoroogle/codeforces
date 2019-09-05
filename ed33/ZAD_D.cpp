#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010];
int main() {
    ll n, d, i, sum = 0, cur = 0, add = 0, ans = 0;
    cin >> n >> d;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        cur += a[i];
        if (a[i] == 0) {
            if (cur + sum >= 0) {
                continue;
            }

            if (cur + sum + add >= 0) {
                add = cur + sum + add;
                sum = -cur;
                continue;
            }

            ++ans;
            add = d;
            sum = -cur;
            continue;
        }

        if (cur + sum > d) {
            cout << -1 << endl;
            return 0;
        }

        add = min(add, d - cur - sum);
    }

    cout << ans << endl;
}
