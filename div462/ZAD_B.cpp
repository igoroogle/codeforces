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
const ll INF = 2E18 + 3;
ll a[55], b[55];
int main() {
    ios_base::sync_with_stdio(0);
    string vans = "888888888888888888";
    ll ans = 36;
    ll n;
    cin >> n;
    if (n > ans) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = vans.length() - 1; i >= 0; --i) {

        if (ans == n) {
            break;
        }

        if (ans - ll(1) == n) {
            --ans;
            vans[i] = '4';
            break;
        }

        vans[i] = '1';
        ans -= 2;
    }
    cout << vans << endl;
}
