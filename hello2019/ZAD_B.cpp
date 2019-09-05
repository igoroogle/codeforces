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
const int MOD = 360;
int a[17];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < (1 << n); ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) {
                ans += a[j];
            } else {
                ans += MOD - a[j];
            }
            ans %= MOD;
        }
        if (ans == 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
