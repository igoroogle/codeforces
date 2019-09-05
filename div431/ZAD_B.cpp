#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
bool is_belong(pair<ll, ll> f, pair<ll, ll> s, pair<ll, ll> p) {
    ll a, b, c;
    a = f.y - s.y;
    b = s.x - f.x;
    c = -(a * f.x + b * f.y);
    return (a * p.x + b * p.y + c == 0);
}

ll ar[1010];
void go_ans(pair<ll, ll> f, pair<ll, ll> s, pair<ll, ll> p) {
    bool ff = false;
    pair<ll, ll> t, vl;
    ll i;
    for (i = 0; i < n; ++i) {
        vl = mp(i, ar[i]);
        if (is_belong(f, s, vl)) {
            continue;
        }

        if (vl == p) {
            continue;
        }

        if (!ff) {
            ff = true;
            t = vl;
            continue;
        }

        //cout << f.x << ' ' << f.y << " wtf" << s.x << ' ' << s.y << " wtf" << p.x << ' ' << p.y << " wtf" << t.x << ' ' << t.y << " wtf" << endl;
        if (!is_belong(p, t, vl)) {
            return;
        }
    }

    if (!ff) {
        cout << "Yes\n";
        exit(0);
    }

    ll a1, b1, c1, a2, b2, c2;
    a1 = f.y - s.y;
    b1 = s.x - f.x;
    c1 = -(a1 * f.x + b1 * f.y);
    a2 = p.y - t.y;
    b2 = t.x - p.x;
    c2 = -(a2 * p.x + b2 * p.y);
    if (a1 * b2 != a2 * b1) {
        return;
    }

    cout << "Yes\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll i;
    pair<ll, ll> a, b, c;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> ar[i];
    }

    bool f = false;
    a = mp(0, ar[0]);
    b = mp(1, ar[1]);
    for (i = 2; i < n; ++i) {
        c = mp(i, ar[i]);
        if (!is_belong(a, b, c)) {
            f = true;
            break;
        }
    }

    if (!f) {
        cout << "No\n";
        return 0;
    }

    go_ans(a, b, c);
    go_ans(a, c, b);
    go_ans(b, c, a);
    cout << "No\n";
}
