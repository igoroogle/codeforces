#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n, i, ans = 1;
    cin >> n;
    for (i = 0; i < n; ++i) {
        ans *= ll(3);
    }
    cout << ans << endl;
}
