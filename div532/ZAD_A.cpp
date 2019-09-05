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
int a[110];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, ans = 0, sum = 0, cn = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < k; ++i) {
        cn = 0;
        for (int j = i; j < n; j += k) {
            cn += a[j];
        }
        ans = max(ans, abs(sum - cn));
    }
    cout << ans << '\n';
}
