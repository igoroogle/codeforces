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
    ll x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    if (t1 * abs(x - y) < t2 * (abs(z - x) + abs(x - y)) + t3 * 3) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
