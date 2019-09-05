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
    ll k, n, s, p, v;
    cin >> k >> n >> s >> p;
    n = ll(n - 1) / s + ll(1);
    n *= k;
    cout << (ll(n - 1) / p + ll(1)) << endl;
}
