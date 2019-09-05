#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_beck
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, seed, vmax, ret;
ll rnd() {
    ret = seed;
    seed = (seed * ll(7) + ll(13)) % ll(1000000007);
    return ret;
}

ll a[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int i, n;
    for (i = 0; i < 100; ++i) {
        cout << rnd() % 100000 + 1 << ' ';
        cout << rnd() % 100000 + 1 << endl;
    }
    cin >> n >> m >> seed >> vmax;
    for (ll i = 0; i < n; ++i) {
        a[i] = (rnd() % vmax) + ll(1);
    }

    ll op, l, r, x, y, op1, op2, op3, op4;

    while (m--) {
        op = (rnd() % ll(4)) + ll(1);
        l = (rnd() % n) + ll(1);
        r = (rnd() % n) + ll(1);
        if (l > r) {
            swap(l, r);
        }

        if (op == 3) {
            x = (rnd() % ll(r - l + 1)) + ll(1);
        } else {
            x = (rnd() % vmax) + ll(1);
        }

        if (op == 4) {
            y = (rnd() % vmax) + ll(1);
        }
    }
}
