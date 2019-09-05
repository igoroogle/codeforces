#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
char a[300010];
ll dp[300010][3];
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n, x, y;
    cin >> n >> x >> y >> s;
    int m = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            a[m++] = a[i];
        }
    }
    n = m;
    if (a[0] == '1') {
        dp[0][0] = y;
    } else {
        dp[0][1] = y;
    }

    for (int i = 1; i < n; ++i) {}

    cout << dp[n][1] << endl;
}
