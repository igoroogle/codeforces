#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, i;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 2; i < n; ++i) {
        if (a[i - 2] + a[i - 1] > a[i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
