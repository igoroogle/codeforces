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

ull get_ans(ull n, ull x) {
    ll m = n / x;
    if (m == ull(1)) {
        return ull(1);
    }
    ull a1 = 1;
    ull an = a1 + x * ull(m - 1);
    ull ans = (a1 + an) * m / ull(2);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    ull n;
    cin >> n;
    vector<ull> ans;
    for (ull i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.pb(get_ans(n, i));
            if (n / i != i) {
                ans.pb(get_ans(n, n / i));
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}
