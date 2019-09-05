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
const ld PI = 3.141592653589793116;

int main() {
    ios_base::sync_with_stdio(0);
    ld n, r;
    cin >> n >> r;
    ld alp = ld(2) * PI / n;
    ld x = r * sin(alp);
    ld ans = x * r / (r - x);
    cout << fixed << setprecision(11) << ans << '\n';
}
