#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    int n, ans = 1, mx, pr, vl = 1, x;
    cin >> n >> pr;
    mx = pr;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (x == pr) {
            ++vl;
        } else {
            vl = 1;
            pr = x;
        }

        if (x > mx) {
            mx = x;
            ans = 1;
        } else if (x == mx) {
            ans = max(ans, vl);
        }
    }

    cout << ans << '\n';
}
