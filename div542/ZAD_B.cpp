#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> id[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n + n; ++i) {
        int x;
        cin >> x;
        --x;
        id[x].pb(i);
    }

    ll ans = 0;
    auto cur = mp(0, 0);
    for (int i = 0; i < n; ++i) {
        ll add = abs(cur.x - id[i][0]) + abs(cur.y - id[i][1]);
        add = min(add, ll(abs(cur.x - id[i][1]) + abs(cur.y - id[i][0])));
        cur = mp(id[i][0], id[i][1]);
        ans += add;
    }

    cout << ans << '\n';
}
