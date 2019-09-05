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
const ll INF = 1E18;
int st[2003];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    char c;
    int ans = 0;
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> c;
                if (c == '.') {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
        return 0;
    }

    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == '.') {
            ++st[0];
            sm = 1;
        } else {
            st[0] = 0;
            sm = 0;
        }

        if (st[0] >= k) {
            ++ans;
        }

        for (int j = 1; j < m; ++j) {
            cin >> c;
            if (c == '.') {
                ++st[j];
                ++sm;
            } else {
                st[j] = 0;
                sm = 0;
            }
            if (st[j] >= k) {
                ++ans;
            }

            if (sm >= k) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}
