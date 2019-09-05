#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll P = 239;
const ll MOD = 3000000019;
ll a[200010];

int main() {
    ios_base::sync_with_stdio(0);
    bool f;
    for (ll i = 3000000000; i <= 4000000000; ++i) {
        f = true;
        for (ll j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << i << endl;
            return 0;
        }
    }
}
