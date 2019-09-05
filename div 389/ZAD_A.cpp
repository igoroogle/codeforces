#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef long double ld;
using namespace std;
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    --k;
    cout << k / ll(2 * m) + ll(1) << ' ';
    k = k % ll(2 * m);
    cout << k / ll(2) + 1 << ' ';
    k = k % ll(2);
    if (k == 0) {
        cout << "L\n";
    } else {
        cout << "R\n";
    }
}
