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
ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll ang;
        cin >> ang;
        cout << ll(180) / gcd(ang, ll(180)) << '\n';
    }
}
