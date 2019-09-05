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
const int INF = 1E9;

int a[200010], b[200010], lf[200010], rf[200010], add[200010], del[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = INF;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            continue;
        }
        if (lf[a[i]] == 0) {
            lf[a[i]] = i + 1;
        }

        rf[a[i]] = max(rf[a[i]], i + 1);
    }

    for (int i = 0; i <= q; ++i) {
        --lf[i];
        --rf[i];
    }

    for (int i = 1; i <= q; ++i) {
        if (lf[i] != -1) {
            add[lf[i]] = i;
            del[rf[i]] = i;
        }
    }

    set<int> zn;
    for (int i = 0; i < n; ++i) {
        if (add[i] != 0) {
            zn.insert(-add[i]);
        }

        if (!zn.empty()) {
            b[i] = -(*zn.begin());
        }

        if (del[i] != 0) {
            zn.erase(-del[i]);
        }
    }

    bool f = false;
    for (int i = 0; i < n; ++i) {
        if (b[i] == q) {
            f = true;
        }
    }

    if (!f) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                b[i] = q;
                f = true;
                break;
            }
        }
    }

    if (!f) {
        cout << "NO\n";
        return 0;
    }

    int cur = 1;
    for (int i = 0; i < n; ++i) {
        if (b[i] != INF) {
            cur = b[i];
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] != INF) {
            cur = b[i];
        } else {
            b[i] = cur;
        }
    }

    for (int i = 0; i < n; ++i) {
        if ((a[i] == b[i]) || (a[i] == 0)) {
            continue;
        }
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    return 0;
}
