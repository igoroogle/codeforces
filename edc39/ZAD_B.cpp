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
    ll a, b;
    cin >> a >> b;
    while ((a != ll(0)) && (b != ll(0))) {
        if (a >= ll(2) * b) {
            a %= ll(2) * b;
        } else if (b >= ll(2) * a) {
            b %= ll(2) * a;
        } else {
            break;
        }
    }
    cout << a << ' ' << b << endl;
}
