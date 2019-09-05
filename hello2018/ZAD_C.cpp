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
typedef unsigned long long ull;
const ull INF = 9223372036854775806;
ull a[32];
int main() {
    ios_base::sync_with_stdio(0);
    //cout << INF << endl;
    ull n, l;
    cin >> n >> l;
    for (ll i = 0; i < 32; ++i) {
        a[i] = INF;
    }

    for (ull i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 30; i >= 0; --i) {
        a[i] = min(a[i], a[i + 1]);
    }

    ull vl;
    for (ull i = 1; i < 32; ++i) {
        /*vl = 0;
        for (ull j = 0; j < i; ++j) {
            vl = min(INF, vl + a[j]);
        }*/

        //vl += a[0];
        //a[i] = min(a[i], vl);
        a[i] = min (a[i - 1] + a[i - 1], a[i]);
    }

    /*for (ull i = 1; i < 32; ++i) {
        vl = 0;
        for (ull j = 0; j < i; ++j) {
            vl = min(INF, vl + a[j]);
        }

        vl += a[0];
        a[i] = min(a[i], vl);
    }*/

    ull ans = 0;
    for (ull i = 0; i < 32; ++i) {
        ans = min(ans, a[i]);
        if ((ull(1) << i) & l) {
            ans += a[i];
        }
    }

    /*for (ull i = 0; i < 32; ++i) {
        if ((ull(1) << i) & l) {
            cout << 1;
        } else {
            cout << 0;
        }
    }*/
    /*cout << endl;
    for (ull i = 0; i < 32; ++i) {
        cout << a[i] << ' ';
    }*/
    //cout << endl;
    ull st = 0;
    while ((ull(1) << st) < l) {
        ++st;
    }

    ans = min(a[st], ans);
    vl = 0;
    if (st > 0) --st;
    while (st > 0) {
        if ((ull(1) << st) & l) {
                vl += a[st];
        }

        if (!((ull(1) << ull(st - 1)) & l)) {
            ans = min(ans, vl + a[st]);
        }
        --st;
    }
    //cout << a[30] << endl;
    cout << ans << endl;
}
