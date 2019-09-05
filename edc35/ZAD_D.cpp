#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
ll a[1503];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, i, sm = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[i]) {
                ++sm;
            }
        }
    }

    cin >> m;

    bool f;
    f = (sm % 2);
    int l, r;
    while (m--) {
        cin >> l >> r;
        if (((r - l + 1) / 2) % 2) {
            f = !f;
        }

        if (f) {
            cout << "odd\n";
        } else {
            cout << "even\n";
        }
    }
}
