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
    int n, x, l = 0, r = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if ((x >= l) && (x <= r)) {
            if (x == r) {
                ++r;
            }
            continue;
        } else {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
