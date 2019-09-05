#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
pair<int, int> a[110];
vector<pair<int, int>> ans;
int main() {
    int l, r, n, i, kl1 = 0, kl2 = 0, vl;
    cin >> n;
    for (i = 0; i < n; ++i) {
        scanf("%d", &vl);
        a[i] = mp(vl, i + 1);
    }

    sort(a + 1, a + n);
    reverse(a + 1, a + n);
    l = 0;
    r = 1;
    while ((r < n) && (l < r)) {
        if (a[l].x == 0) {
            ++l;
            continue;
        }

        ans.pb(mp(a[l].y, a[r].y));
        --a[l].x;
        ++r;
    }

    if (ans.size() != n - 1) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].x, ans[i].y);
    }
}
