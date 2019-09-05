#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
ll ans[110];
int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    for (ll i = 3; i <= n; ++i) {
        ans[i] = i + ans[i - 2];
    }

    cout << ans[n] << endl;
}
