#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int a[1010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = a[0];
    for (int i = 1; i < n; ++i) {
        ans = gcd(ans, a[i]);
    }

    if (ans != a[0]) {
        cout << -1 << endl;
        return 0;
    }

    cout << n + n << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ' << a[0] << ' ';
    }
}
