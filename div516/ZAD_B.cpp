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
const int DL = 32;
int dp[DL][2];

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int ans = 1;
        while (a > 0) {
            if (a % 2) {
                ans *= 2;
            }
            a >>= 1;
        }
        cout << ans << '\n';
    }
}
