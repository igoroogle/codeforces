#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[1000100];
int main() {
    ios_base::sync_with_stdio(0);
    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        --a[max(0, i - x)];
        ++a[i];
    }

    x = 0;
    for (int i = 0; i < n; ++i) {
        x += a[i];
        if (x == 0) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}