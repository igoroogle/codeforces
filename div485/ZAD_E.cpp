#include<bits/stdc++.h>
#define pb push_back
#define em emplace_back
#define mp make_pair
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef long double ld;

ll f[1000003];
const int DL = 1000003;

ll get (int n) {
    ll ans = 0;
    for (int i = n; i >= 0; i = ((i + 1) & i) - 1) {
        ans += f[i];
    }
    return ans;
}

void upd (int ind) {
    for (int i = ind; i < DL; i = ((i + 1) | i)) {
        ++f[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll x, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        upd(x);
        ans += x - get(x);
    }

    if (((!(ans & ll(1))) && (n & ll(1))) || ((ans & ll(1)) && (!(n & ll(1))))) {
        cout << "Um_nik\n";
    } else {
        cout << "Petr\n";
    }
}
