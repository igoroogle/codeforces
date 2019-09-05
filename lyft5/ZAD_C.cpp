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

const int INF = 1E9 + 1;

int a[100010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    map<int, int> val;

    set<pair<int, int>> setl, setr;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int x1, x2, y;

    setl.insert(mp(INF, INF));
    setr.insert(mp(INF, INF));
    int cans = 0, cor = 2;

    for (int i = 0; i < m; ++i) {
        cin >> x1 >> x2 >> y;
        setr.insert(mp(x2, y));
        if (x1 == 1) {
            ++val[y];
            if (val[y] == 1) {
                ++cans;
            }
        } else {
            setl.insert(mp(x1, y));
        }
    }

    a[n] = 1E9;
    int ans = cans;
    for (int i = 0; i <= n; ++i) {
        while (cor <= a[i]) {
            while ((setl.begin()->x) <= cor) {
                if (val[setl.begin()->y] > 0) {
                    ++val[setl.begin()->y];
                }
                setl.erase(setl.begin());
            }

            while ((setr.begin()->x) < cor) {
                if (val[setr.begin()->y] > 0) {
                    --val[setr.begin()->y];
                    if (val[setr.begin()->y] == 0) {
                        --cans;
                    }
                }
                setr.erase(setr.begin());
            }

            ans = min(ans, cans + i);
            cor = min((setl.begin()->x), (setr.begin()->x) + 1);
        }
    }

    cout << ans << '\n';
}
