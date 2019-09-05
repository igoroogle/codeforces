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
typedef pair<int, int> pii;

set<int> ed[300010];

bool is_ed(int u, int v) {
    return (ed[u].find(v) != ed[u].end());
}

void do_it(vector<int>& a, int l, int r, vector<int>& ans) {
    int st = ans.size();
    int ind = -1;
    for (int i = r; i >= l; --i) {
        if (is_ed(a[i], a[r])) {
            ans.pb(a[i]);
        } else {
            ind = i;
            break;
        }
    }

    if (ind != -1) {
        vector<int> to_ans;
        do_it(a, l, ind, to_ans);
        to_ans.pb(a[r]);
        do_it(to_ans, 0, int(to_ans.size()) - 1, ans);
    }

    reverse(ans.begin() + st, ans.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    while(m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ed[u].insert(v);
    }

    vector<int> ans;
    do_it(p, 0, n - 1, ans);
    cout << ans.size() << '\n';
}
