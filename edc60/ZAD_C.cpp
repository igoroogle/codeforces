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

ll sx[100010], sy[100010];

ll sign(ll x) {
    if (x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}

bool get(ll x1, ll y1, ll x2, ll y2, ll i, ll k, ll n) {
    x1 = x1 + sx[n - 1] * k + sx[i];
    y1 = y1 + sy[n - 1] * k + sy[i];
    //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << k << ' ' << i << endl;
    if (abs(x1 - x2) + abs(y1 - y2) <= k * n + i + ll(1)) {
        //cout << "WTF\n";
        //cout << k * n + i + ll(1) << endl;
        return true;
    } else {
        return false;
    }
}

ll get_max(ll x1, ll y1, ll x2, ll y2, ll i, ll n) {
    ll xx1 = x1 + sx[i];
    ll yy1 = y1 + sy[i];
    ll ans = -1;
    if (get(x1, y1, x2, y2, i, 0, n)) {
       ans = i + ll(1);
    }

    ll k;
    k = abs(x2 - xx1) / n;
    if (get(x1, y1, x2, y2, i, k, n)) {
        if (ans != -1) {
            ans = min(k * n + i + ll(1), ans);
        } else {
            ans = k * n + i + ll(1);
        }
    }

    ++k;
    if (get(x1, y1, x2, y2, i, k, n)) {
        if (ans != -1) {
            ans = min(k * n + i + ll(1), ans);
        } else {
            ans = k * n + i + ll(1);
        }
    }

    k = abs(y2 - yy1) / n;
    if (get(x1, y1, x2, y2, i, k, n)) {
        if (ans != -1) {
            ans = min(k * n + i + ll(1), ans);
        } else {
            ans = k * n + i + ll(1);
        }
    }

    ++k;
    if (get(x1, y1, x2, y2, i, k, n)) {
        if (ans != -1) {
            ans = min(k * n + i + ll(1), ans);
        } else {
            ans = k * n + i + ll(1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll n;
    cin >> n;
    sx[0] = 0;
    sy[0] = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            ++sy[i];
        } else if (s[i] == 'D') {
            --sy[i];
        } else if (s[i] == 'L') {
            --sx[i];
        } else if (s[i] == 'R') {
            ++sx[i];
        }

        sx[i + 1] = sx[i];
        sy[i + 1] = sy[i];
    }

    ll ans = -1;
    /*for (int i = 0; i < n; ++i) {
        //cout << sx[i] << ' ' << sy[i] << endl;
        ll vt = get_max(x1, y1, x2, y2, i, n);
        //cout << vt << ' ' << i << endl;
        if (vt == -1) {
            continue;
        }

        if ((ans == -1) || (vt < ans)) {
            ans = vt;
        }
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1001; ++j) {
            if (get(x1, y1, x2, y2, i, j, n)) {
                ll vt = ll(j) * n + ll(i) + ll(1);
                if ((ans == -1) || (vt < ans)) {
                    ans = vt;
                }
            }
        }
    }

    cout << ans << '\n';
}
