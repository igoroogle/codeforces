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
    int q;
    cin >> q;
    while (q--) {
        ll k, x;
        cin >> k >> x;
        cout << ll(k - 1) * ll(9) + x << '\n';
    }
}
