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
ll a[1010];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ll x, y = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[i] = x - y;
        y = x;
    }


    vector<int> ans;
    for (int len = 1; len <= n; ++len) {
        ans.pb(len);
        for (int i = 0; i < n; ++i) {
            if (a[i] != a[i % len]) {
                ans.pop_back();
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}
