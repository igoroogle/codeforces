#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll n, x = 2, i, vl;
    cin >> n >> vl;
    ld ans = 1E18;
    for (i = 2; i < n; ++i) {
        if (abs(ld(180) * ld(n - i) / ld(n) - ld(vl)) < ans) {
            ans = abs(ld(180) * ld(n - i) / ld(n) - ld(vl));
            x = i;
        }
    }

    cout << x << ' ' << 1 << ' ' << n << endl;
}
