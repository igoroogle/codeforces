#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef unsigned int uni;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    if (n < m) {
        swap(n, m);
    }

    while ((m > 1) && (k > 0)) {
        ans += m * 2 + (n - 2) * 2;
        n -= 4;
        m -= 4;
        --k;
    }

    if ((m == 1) && (k > 0)) {
        ans += n;
    }

    cout << ans << endl;
}
