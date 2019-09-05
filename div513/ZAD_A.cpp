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

int main() {
    ios_base::sync_with_stdio(0);
    int n, x, vx = 0, vy = 0;
    string s;
    cin >> n >> s;
    for (auto cur : s) {
        if (cur == '8') {
            ++vx;
        } else {
            ++vy;
        }
    }

    int ans = 0;
    for (int i = 1; i <= vx; ++i) {
        ans = max(min(i, (vy + vx - i) / 10), ans);
    }

    cout << ans << '\n';
}
