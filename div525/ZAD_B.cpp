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

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    set<ll> t;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        t.insert(x);
    }

    ll add = 0;
    for (int i = 0; i < k; ++i) {
        while ((!t.empty()) && ((*t.begin()) - add <= 0)) {
            t.erase(t.begin());
        }

        if (t.empty()) {
            cout << 0 << '\n';
        } else {
            cout << (*t.begin()) - add << '\n';
            add = (*t.begin());
        }
    }
}
