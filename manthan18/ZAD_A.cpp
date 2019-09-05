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
    ll n, sm = 0;
    cin >> n;
    for (int i = 0; i <= 60; ++i) {
        sm += (ll(1) << ll(i));
        if (sm >= n) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
