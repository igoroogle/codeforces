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
pair<pair<int, int>, string> a[100010];
bool comp(
pair<pair<int, int>, string> f,
pair<pair<int, int>, string> l) {
    return (ll(f.x.x) * ll(l.x.y) > ll(l.x.x) * ll(f.x.y));
}
int main() {
    ios_base::sync_with_stdio(0);
    int n, i;
    ll h, s;
    string st;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> st;
        h = 0;
        s = 0;
        for (auto cur : st) {
            if (cur == 'h') {
                ++h;
            } else if (cur == 's') {
                ++s;
            }
        }

        a[i] = mp(mp(s, h), st);
    }
    sort(a, a + n, comp);
    h = 0;
    s = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < a[i].y.length(); ++j) {
            if (a[i].y[j] == 's') {
                ++s;
            } else if (a[i].y[j] == 'h') {
                ans += ll(s);
            }
        }
    }
    cout << ans << endl;
}
