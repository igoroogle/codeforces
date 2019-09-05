#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n, ans;
    char c;
    cin >> n >> c;
    --n;
    ans = (n / ll(4)) * ll(16);
    n = n % ll(4);
    if (n % ll(2)) {
        ans += ll(7);
    }

    if (c == 'f')
        ++ans;
    else if (c == 'e') {
        ans += ll(2);
    }
    else if (c == 'd') {
        ans += ll(3);
    }
    else if (c == 'a') {
        ans += ll(4);
    }
    else if (c == 'b') {
        ans += ll(5);
    }
    else if (c == 'c') {
        ans += ll(6);
    }

    cout << ans << endl;
}
