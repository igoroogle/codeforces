#include<algorithm>
#include<map>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
ll ans[1000100];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, a, b, x = -1, y = -1;
    cin >> n >> a >> b;
    for (ll i  = 0; i * a <= n; ++i) {
        if ((n - i * a) % b == 0) {
            x = i;
            y = (n - i * a) / b;
            break;
        }
    }

    if (x == -1) {
        cout << -1 << endl;
        return 0;
    }

    ll vl = 1;
    for (int i = 0; i < x; ++i)  {
        for (int j = vl; j < vl + a - 1; ++j) {
            ans[j] = j + 1;
        }
        ans[vl + a - 1] = vl;
        vl += a;
    }

    for (int i = 0; i < y; ++i)  {
        for (int j = vl; j < vl + b - 1; ++j) {
            ans[j] = j + 1;
        }
        ans[vl + b - 1] = vl;
        vl += b;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}
