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
const ll INF = 2E18 + 3;
const ll DL = 31623;
ll issqr(ll n) {
    ll sq = ll(sqrt(ld(n)));
    for (ll i = max(sq - ll(2), ll(0)); i < sq + ll(3); ++i) {
        if (i * i == n) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    for (ll i = 1E8; i <= 1E8 + 1000; ++i) {
        cout << i * i << endl;
    }
}
