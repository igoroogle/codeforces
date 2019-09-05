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

    if (k == ll(2)) {
        cout << "YES\n";
        cout << "0 0\n";
        cout << n << " 0\n";
        cout << "0 " << m << '\n';
        return 0;
    }

    //s /= k;
    if (k % ll(2) == 0) {
        k /= ll(2);
    }

    for (ll i = 1; i * i <= k; ++i) {
        if (k % i == ll(0)) {
           ll k1 = i;
           ll k2 = k / i;
           ll nn = n, mm = m;
           if ((n % k1 == ll(0)) && (m % k2 == ll(0))) {
                if (k1 == ll(1)) {
                    mm *= ll(2);
                } else {
                    nn *= ll(2);
                }
                nn /= k1;
                mm /= k2;
                cout << "YES\n";
                cout << "0 0\n";
                cout << nn << " 0\n";
                cout << "0 " << mm << '\n';
                return 0;
           }

           swap(k1, k2);
           if ((n % k1 == ll(0)) && (m % k2 == ll(0))) {
                if (k1 == ll(1)) {
                    mm *= ll(2);
                } else {
                    nn *= ll(2);
                }
                nn /= k1;
                mm /= k2;
                cout << "YES\n";
                cout << "0 0\n";
                cout << nn << " 0\n";
                cout << "0 " << mm << '\n';
                return 0;
           }
        }
    }

    //for(;;);
}
