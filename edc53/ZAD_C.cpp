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
ll sumx[200010], sumy[200010];
ll n;
ll x, y;

bool check(ll len) {
    if (len < 0) {
        return true;
    }

    if (len == n + 1) {
        return false;
    }

    if (len == 0) {
        if ((sumx[n] == x) && (sumy[n] == y)) {
            return false;
        } else {
            return true;
        }
    }

    for (ll i = 1; i <= n - len + 1; ++i) {
        ll vlx = sumx[i - 1] + sumx[n + 1] - sumx[i + len - 1];
        ll vly = sumy[i - 1] + sumy[n + 1] - sumy[i + len - 1];
        //cout << vlx << ' ' << vly << ' ' << x << ' ' << y << ' ' << len << endl;
        if ((abs(vlx - x) + abs(vly - y) <= len) && ((len - abs(vlx - x) - abs(vly - y)) % ll(2) == 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    string s;
    cin >> s;
    for (ll i = 1; i <= n; ++i) {
        sumx[i] = sumx[i - 1];
        sumy[i] = sumy[i - 1];
        if (s[i - 1] == 'L') {
            --sumx[i];
        } else if (s[i - 1] == 'R') {
            ++sumx[i];
        } else if (s[i - 1] == 'D') {
            --sumy[i];
        } else if (s[i - 1] == 'U') {
            ++sumy[i];
        }
    }
    sumx[n + 1] = sumx[n];
    sumy[n + 1] = sumy[n];
    cin >> x >> y;


    ll l = 0, r = n + 1;
    while (l < r) {
        ll m = (l + r) >> ll(1);
        if (check(m) && check(m - 1)) {
            l = m + 1;
        } else {
            r = m;
        }
    }


    /*for (ll i = 0; i <= n; ++i) {
        if (!check(i)) {
            cout << i << endl;
            return 0;
        }
    }*/
    if (l == n + 1) {
        cout << -1 << '\n';
    } else {
        cout << l << '\n';
    }
}
