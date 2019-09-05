#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define em emplace_back
#define sqr(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int a[9];
void rec(int k, int vl1, int vl2) {
    if (max(vl1, vl2) > n) {
        return;
    }
    ++a[k];
    int l = 0, r = 9;
    while (l < r) {
        rec(k + 1, vl1 * 10 + l, vl2 * 10 + r);
        rec(k + 1, vl1 * 10 + r, vl2 * 10 + l);
        ++l;
        --r;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    rec(0, 0, 0);
    int ans = 0;
    a[0] = n * ll(n + 1) / ll(2);
    for (int i = 8; i >= 0; --i) {
        if (a[i] > 0) {
            ans = a[i];
            if (i > 0) {
                ans >>= 1;
            }
            break;
        }
    }
    cout << ans << '\n';
}
