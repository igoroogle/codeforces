#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> ed[200010];
bool use[200010];
set<int> q[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        --x;
        --y;
        ed[x].pb(y);
        ed[y].pb(x);
    }

    int l = 0, r = 0;
    q[0].insert(0);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        --x;
        while ((l <= r) && (q[l].empty())) {
            ++l;
        }

        if ((use[x]) || (l > r) || (q[l].find(x) == q[l].end())) {
            cout << "No\n";
            return 0;
        }

        use[x] = true;
        q[l].erase(x);
        ++r;
        for (auto v : ed[x]) {
            if (!use[v]) {
                q[r].insert(v);
            }
        }
    }
    cout << "Yes\n";
}
