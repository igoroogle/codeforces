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
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i < n; ++i) {
        if (n % i == 0) {
            ++ans;
        }
    }
    cout << ans << endl;
}
