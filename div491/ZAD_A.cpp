#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    if ((a + b - c >= n) || (c > a) || (c > b)) {
        cout << -1 << endl;
    } else {
        cout << n - a - b + c << endl;
    }
}
