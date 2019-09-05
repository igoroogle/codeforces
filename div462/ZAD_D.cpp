#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
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
vector<ll> ans;
int main() {
    ios_base::sync_with_stdio(0);
    ll p, k, b = 0;
    cin >> p >> k;
    if (p < k) {
        cout << 1 << endl;
        cout << p << endl;
        return 0;
    }

    for (ll i = 1; i < k; ++i) {
        if ((p + k) % i) {
            continue;
        }
        ans.clear();
        ans.pb(i);
        b = (p + k) / i;
        while (b >= k) {
            for (int j = 1; j * j <= b; ++j) {
                if ((b + k) % j == 0) {
                    ans.pb(j);
                    b = (b + k) / j;
                }
            }
            ans.pb(b);
        }
        ans.pb(b);
        break;
    }

    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size();
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}
