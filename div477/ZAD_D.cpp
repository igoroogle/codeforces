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

pair<ll, ll> c[300010];

void getIt(int i, ll x1, ll x2, ll n, bool f) {
    ll vl = (x1 - ll(1)) / c[i].x + ll(1);
    if (vl >= n - i) {
        return;
    }

    ll j = vl + i;
    ll vl2 = (x2 - ll(1)) / c[j].x + ll(1);
    if (vl2 > n - j) {
        return;
    }

    cout << "Yes\n";

    if (f) {
        cout << vl2 << ' ' << vl << '\n';

        for (int k = j; k < j + vl2; ++k) {
            cout << c[k].y + 1 << ' ';
        }
        cout << '\n';

        for (int k = i; k < i + vl; ++k) {
            cout << c[k].y + 1 << ' ';
        }
        cout << '\n';
        exit(0);

    }

    cout << vl << ' ' << vl2 << '\n';

    for (int k = i; k < i + vl; ++k) {
        cout << c[k].y + 1 << ' ';
    }
    cout << '\n';

    for (int k = j; k < j + vl2; ++k) {
        cout << c[k].y + 1 << ' ';
    }
    cout << '\n';

    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, x1, x2, x;
    cin >> n >> x1 >> x2;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        c[i] = mp(x, i);
    }
    sort(c, c + n);

    for (int i = 0; i < n; ++i) {
        getIt(i, x1, x2, n, 0);
        getIt(i, x2, x1, n, 1);
    }

    cout << "No\n";
}
