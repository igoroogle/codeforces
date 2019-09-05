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
ll a[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, s = 0, ss = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }

    for (int i = 0; i < n; ++i) {
        ss += a[i];
        if (ss * ll(2) >= s) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
