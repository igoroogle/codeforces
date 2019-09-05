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

int lef[100010], a[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    lef[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            lef[i] = lef[i - 1];
        } else {
            lef[i] = i;
        }
    }

    int ans = 0;
    for (int i = n - 1; i > 0; --i) {
        if (lef[i] == 0) {
            break;
        }

        if (i - lef[i] <= lef[i] - 1 - lef[lef[i] - 1]) {
            ans = max((i - lef[i] + 1) * 2, ans);
        }
    }

    cout << ans << '\n';
}
