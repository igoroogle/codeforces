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

vector<pair<ll, ll>> vt;

void rec(int ind, ll val, ll n, ll m, ll s) {
    if (ind == int(vt.size())) {
        if ((val <= n) && (s / val <= m)) {
            cout << "YES\n";
            cout << "0 0\n";
            cout << val << " 0\n";
            cout << "0 " << s / val << '\n';
            exit(0);
        }

        if ((s / val <= n) && (val <= m)) {
            cout << "YES\n";
            cout << "0 0\n";
            cout << s / val << " 0\n";
            cout << "0 " << val << '\n';
            exit(0);
        }

        return;
    }

    ll pw = 1;
    for (int i = 0; i <= vt[ind].y; ++i) {
        rec(ind + 1, val * pw, n, m, s);
        pw *= vt[ind].x;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll s = ll(2) * n * m;
    if (s % k != ll(0)) {
        cout << "NO\n";
        return 0;
    }

    s /= k;
    vector<ll> q;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == ll(0)) {
            q.pb(i);
            q.pb(n / i);
        }
    }

    for (int i = 2; i * i <= m; ++i) {
        if (m % i == ll(0)) {
            q.pb(i);
            q.pb(m / i);
        }
    }
    q.pb(n);
    q.pb(m);
    q.pb(ll(2));

    sort(q.begin(), q.end());
    ll ss = s, i = 0;
    while (q[i] * q[i] <= ss) {
        if (ss % q[i] == 0) {
            vt.em(q[i], ll(0));
        }

        while (ss % q[i] == 0) {
            ss /= q[i];
            ++vt.back().y;
        }
        ++i;
    }

    rec(0, 1, n, m, s);
    cout << "NO\n";
}
