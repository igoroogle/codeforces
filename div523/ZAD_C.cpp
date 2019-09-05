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
const ll MOD = 1E9 + 7;
const int DL = 1E6 + 3;
ll ans[DL];

int main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n;
    ans[0] = 1;
    while(n--) {
        cin >> x;
        vector<pair<int, int>> ar;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                ar.em(i, ans[i - 1]);
                if (x / i != i) {
                    ar.em(x / i, ans[x / i - 1]);
                }
            }
        }
        for (auto cur : ar) {
            ans[cur.x] = (ans[cur.x] + cur.y) % MOD;
        }
    }

    ll vans = 0;
    for (int i = 1; i < DL; ++i) {
        vans = (vans + ans[i]) % MOD;
    }

    cout << vans << '\n';
}
