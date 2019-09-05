#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
ll b[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, sm = 0, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sm += x;
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(b, b + n);
    reverse(b, b + n);

    if (b[0] + b[1] >= sm) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}