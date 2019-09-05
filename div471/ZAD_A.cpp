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
    ll hh, mm;
    cin >> hh >> mm;
    mm = hh * 60 + mm;
    ll h, d, n;
    ld c;
    cin >> h >> d >> c >> n;
    ll ans = (h - 1) / n + 1;
    while (mm < 20 * 60) {
        ++mm;
        h += d;
    }
    cout << h  << endl;
    ll toans = (h - 1) / n + 1;
    cout << ans << ' ' << toans << endl;
    ld cc = ld(0.2) * ld(c);
    ld getans =  min(ld(ans) * c, cc * ld(toans));
    cout << fixed << setprecision(11) << getans << '\n';
}
