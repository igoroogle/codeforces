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

int main() {
    ios_base::sync_with_stdio(0);
    ll w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    while (h > 0) {
        w += h;
        if (d1 == h) {
            w -= u1;
        } else if (d2 == h) {
            w -= u2;
        }

        w = max(ll(0), w);
        --h;
    }

    cout << w << '\n';
    return 0;
}
