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
int a[111];
int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }

    int kl = 0;
    for (int i = 0; i < 111; ++i) {
        if (a[i] == 0) {
            continue;
        }
        kl = max(kl, (a[i] - 1) / k + 1);
    }

    ll ans = 0;
    for (int i = 0; i < 111; ++i) {
        if (a[i] != 0) {
            ans += kl * k - a[i];
        }
    }

    cout << ans << endl;
}
