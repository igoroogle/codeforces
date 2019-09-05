#include<iostream>
#include<iostream>
#include<iostream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<utility>
#include<cmath>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<int, ll>> ed[100010];
bool use[100010];

ll dfs(int v) {
    use[v] = true;
    ll ans = 0;
    for (auto cur : ed[v]) {
        ans += cur.y;
        if (!use[cur.x]) {
            ans += dfs(cur.x);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ed[i].em(i / j, ll(j));
                ed[i / j].em(i, ll(j));
                if (i / j != j) {
                    ed[i].em(j, ll(i / j));
                    ed[j].em(i, ll(i / j));
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (!use[i]) {
            ans = max(ans, dfs(i));
        }
    }
    cout << ans * ll(2) << '\n';
}