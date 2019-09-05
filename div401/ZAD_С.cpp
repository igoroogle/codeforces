#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
vector< vector<int> > a, b;
int ans[100010];
vector<int> c;
int main() {
    int i, j, n, m, x, k, l, r;
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        a.pb(c);
        b.pb(c);
        ans[i] = i;
        for (j = 0; j < m; ++j) {
            scanf("%d", &x);
            a[i].pb(x);
            if ((i == 0) || (a[i - 1][j] > x)) {
                b[i].pb(i);
            } else {
                b[i].pb(b[i - 1][j]);
            }
            ans[i] = min(ans[i], b[i][j]);
        }
    }

    cin >> k;
    while (k--) {
        scanf("%d%d", &l, &r);
        --r;
        --l;
        if ((l == r) || (ans[r] <= l)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
