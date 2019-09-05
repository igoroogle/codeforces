#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 447;
ll a[200610], b[200610];
ll num(ll i, ll x) {
    ll l = i * DL, r = i * DL + DL - 1, m;
    while (l < r) {
        m = (l + r) >> ll(1);
        if (b[m] < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}
ll get_block(ll i, ll x) {
    ll l = num(i, x);

    if (b[l] < x) {
        return DL;
    }

    return l - i * DL;
}

void ins(ll x, ll y) {
    ll pos1 = num(x / DL, a[x]), pos2 = num(y / DL, a[y]);
    ll v1 = a[x], v2 = a[y], l = x / DL * DL;
    ll r = l + DL - 1, cur = pos1;
    swap(a[x], a[y]);
    b[pos1] = v2;
    while ((cur > l) && (b[cur - 1] > b[cur])) {
        swap(b[cur - 1], b[cur]);
        --cur;
    }

    while ((cur < r) && (b[cur + 1] < b[cur])) {
        swap(b[cur + 1], b[cur]);
        ++cur;
    }

    l = y / DL * DL;
    r = l + DL - 1;
    b[pos2] = v1;
    cur = pos2;
    while ((cur > l) && (b[cur - 1] > b[cur])) {
        swap(b[cur - 1], b[cur]);
        --cur;
    }

    while ((cur < r) && (b[cur + 1] < b[cur])) {
        swap(b[cur + 1], b[cur]);
        ++cur;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    ll n, q, i, x, y, l, r, v1, v2, ans = 0, val;
    cin >> n >> q;
    for (i = 0; i < n + DL; ++i) {
        a[i] = i;
        b[i] = i;
    }

    while (q--) {
        cin >> x >> y;
        if (x == y) {
            cout << ans << "\n";
            continue;
        }

        --x;
        --y;
        if (x > y) {
            swap(x, y);
        }

        l = x + 1;
        r = y - 1;
        v1 = a[x];
        v2 = a[y];
        if (v1 < v2) {
            ++ans;
        } else {
            --ans;
        }

        while ((r >= l) && (r % DL != DL - 1)) {
            if (a[r] < v2) {
                ++ans;
            } else {
                --ans;
            }

            if (a[r] < v1) {
                --ans;
            } else {
                ++ans;
            }

            --r;
        }

        while ((r >= l) && (l % DL != 0)) {
            if (a[l] < v2) {
                ++ans;
            } else {
                --ans;
            }

            if (a[l] < v1) {
                --ans;
            } else {
                ++ans;
            }
            ++l;
        }

        if (l < r) {
            l = l / DL;
            r = r / DL;
            for (i = l; i <= r; ++i) {
                val = get_block(i, v1);
                ans -= val;
                ans += DL - val;

                val = get_block(i, v2);
                ans += val;
                ans -= DL - val;
            }
        }

        cout << ans << "\n";
        ins(x, y);
    }
}
