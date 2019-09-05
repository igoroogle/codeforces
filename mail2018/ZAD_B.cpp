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
ll a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    ll l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    if (a[0] > l) {
        ++ans;
    }

    for (int i = 1; i < n; ++i) {
        if ((a[i] > l) && (a[i - 1] <= l)) {
            ++ans;
        }
    }


    while(m--) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << ans << '\n';
            continue;
        }

        int p;
        ll d;
        cin >> p >> d;
        --p;
        if ((a[p] <= l) && (a[p] + d > l)) {
            if ((((p == 0) || (a[p - 1] <= l))) && (((p == n - 1) || (a[p + 1] <= l)))) {
                ++ans;
            } else if ((((p > 0) && (a[p - 1] > l))) && (((p < n - 1) && (a[p + 1] > l)))) {
                --ans;
            }
        }
        a[p] += d;
    }
}
