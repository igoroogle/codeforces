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

vector<int> a[5010];
vector<int> id;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        a[x].pb(y);
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, int(a[i].size()));
    }

    ll ans = ll(mx - 1) * ll(n);
    for (int i = 0; i < n; ++i) {
        if ()
    }
}
