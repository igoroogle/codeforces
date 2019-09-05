#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(0);
    ll c, v0, v1, a, l, ans = 0, cur = 0, scr;
    cin >> c >> v0 >> v1 >> a >> l;
    scr = v0;
    cur = l;
    for (;;) {
        ++ans;
        cur = cur - l + scr;
        if (cur >= c) {
            break;
        }
        scr = min(scr + a, v1);
    }

    cout << ans << endl;
}
