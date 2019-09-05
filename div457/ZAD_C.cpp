#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 100010;
const ll DL2 = 200030;
bool prost(ll x) {
    if (x < 2) {
        return false;
    }

    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

ll a[DL2];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, sm = 0, ans = 0, vl;
    cin >> n >> m;
    sm = n - 2;

    vl = sm + 1;
    while (!prost(vl)) {
        ++vl;
    }
    cout << vl << ' ' << vl << '\n';


    for (ll i = 2; i < n; ++i) {
        ++ans;
        cout << i - 1 << ' ' << i << " 1\n";
    }
    cout << n - 1 << ' ' << n << ' ' << vl - sm << '\n';
    ++ans;

    for (ll i = 1; i < n; ++i) {
        if (ans == m) {
            break;
        }
        for (ll j = i + 2; j <= n; ++j) {
            if (ans == m) {
                break;
            }
            cout << i << ' ' << j << " 1000000000\n";
            ++ans;
        }
    }
}
