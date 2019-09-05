#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
ll getSecStep(ll x) {
    if (x == 0) {
        return 0;
    }

    ll y = 1;
    while  ((y << ll(1)) <= x) {
        y <<= ll(1);
    }
    return y;
}

vector<ll> ans;

int main() {
    ios_base::sync_with_stdio(0);
    ll x, d, add = 1;
    cin >> x >> d;
    while (x > 0) {
        ll y = getSecStep(x);
        if (y != 1) {
            for (ll z = 2; z <= y; z *= ll(2)) {
                ans.pb(add);
            }
            add += d;
            ans.pb(add);
        } else {
            ans.pb(add);
        }

        add += d;
        x -= y;
    }

    cout << ans.size() << endl;
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}
