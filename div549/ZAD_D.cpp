#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const ll INF = 2E18;

ll gcd(ll a, ll b) {
    if (a == ll(0)) {
        return b;
    }

    if (b == ll(0)) {
        return a;
    }

    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    if (((a == ll(0))) && (b == ll(0))) {
        return ll(0);
    }

    return a / gcd(a, b) * b;
}

vector<ll> fr, sc;

ll getAns(ll n, ll k, ll l) {
    ll vl = l % (n * k);
    if (vl == 0) {
        return ll(1);
    }
    vl = l;
    ll ans = n * k / gcd(vl, n * k);
    //ll ans = lcm(vl, n * k);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    for (ll i = 0; i < k; ++i) {
        int vl = min(i, k - i);
        if (vl == a){
            fr.pb(i);
        }

        if (vl == b) {
            sc.pb(i);
        }
    }

    ll x = INF, y = 0;
    for (auto cur : fr) {
        for (auto cur2 : sc) {
            for (ll i = 0; i <= n + 1; ++i) {
                if (cur >= cur2 + i * k) {
                    continue;
                }
                ll l = cur2 + i * k - cur;
                ll val = getAns(n, k, l);
                x = min(val, x);
                y = max(val, y);
            }
        }
    }

    cout << x << ' ' << y << '\n';
}
