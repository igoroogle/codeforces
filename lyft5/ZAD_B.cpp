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
int t[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n + m; ++i) {
        cin >> t[i];
    }

    int lf = -1, rf = -1, l = 0, r = 0;
    for (int i = 0; i < n + m; ++i) {
        if (t[i] == 0) {
            continue;
        }

        rf = i + 1;
        while ((rf < n + m) && (t[rf] == 0)) {
            ++rf;
        }

        int ans = 0;
        if (lf == -1) {
            ans += i;
        } else {
            l = max(l, lf + 1);
            while ((l < i) && (a[i] - a[l] >= a[l] - a[lf])) {
                ++l;
            }
            ans += (i - l);
        }

        if (rf >= n + m) {
            ans += n + m - i - 1;
        } else {
            r = i + 1;
            while (a[rf] - a[r] >= a[r] - a[i]) {
                ++r;
                ++ans;
            }
        }

        cout << ans << ' ';
        lf = i;
    }
}
