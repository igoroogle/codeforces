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
const int DL = 10000;

int a[5010], b[5010], ans[5010];
bool vl[5010];

ll getAns(ll x) {
    if (x == 0) {
        return x;
    }

    ll y = x;
    ll i = 2;
    while (i * i <= x) {
        if (x % i == 0) {
            while (y % (sqr(i)) == 0) {
                y /= (sqr(i));
            }

            while (x % i == 0) {
                x /= i;
            }
        }
        ++i;
    }

    if (x > 1) {
        while (y % (sqr(x)) == 0) {
            y /= (sqr(x));
        }
    }

    return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    ll y;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        y = getAns(abs(ll(x)));
        if (x < 0) {
            x = -int(y);
        } else {
            x = int(y);
        }
        a[i] = x;
        b[i] = x;
    }


    sort(b, b + n);
    int kl = 0;
    map<int, int> t;
    for (int i = 1; i < n; ++i) {
        if (b[i] != b[i - 1]) {
            ++kl;
            t[b[i]] = kl;
        }
    }

    for (int i = 0; i < n; ++i) {
        a[i] = t[a[i]];
    }

    for (int i = 0; i < n; ++i) {
        int dif = 0;
        for (int j = i; j < n; ++j) {
            if (!vl[a[j]]) {
                ++dif;
            }
            vl[a[j]] = true;
            ++ans[dif];
        }

        for (int j = i; j < n; ++j) {
            vl[a[j]] = false;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}
