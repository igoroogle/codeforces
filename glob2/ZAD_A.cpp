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
typedef pair<int, int> pii;

int a[300010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (a[n - 1] != a[0]) {
        cout << n - 1 << '\n';
        return 0;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] != a[0]) {
            ans = max(ans, max(n - 1 - i, i));
        }
    }

    cout << ans << '\n';
}
