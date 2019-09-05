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
const ll INF = 1E18 + 3;
const ll DL = 31623;
ll sm[100010], n;
ll check(ll l, ll r) {
    if (l <= r) {
        return sm[r] - sm[l - 1];
    }

    return sm[n] - sm[l - 1] + sm[r];
}

int main() {
    ios_base::sync_with_stdio(0);
    ll f, s;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> sm[i];
        sm[i] += sm[i - 1];
    }
    cin >> f >> s;
    --s;

    ll ans = 0, tim = 1;
    ll fr, sc;
    for (ll i = 1; i <= n; ++i) {
        if (f >= i) {
            fr = f - i + ll(1);
        } else {
            fr = n - (i - f - ll(1));
        }

        if (s >= i) {
            sc = s - i + ll(1);
        } else {
            sc = n - (i - s - ll(1));
        }

        ll toans = check((f - i + n) % n + ll(1), (s - i + n) % n + ll(1));
        if (toans > ans) {
            //cout << toans << endl;
            tim = i;
            ans = toans;
        }
    }
    cout << tim << endl;
}
