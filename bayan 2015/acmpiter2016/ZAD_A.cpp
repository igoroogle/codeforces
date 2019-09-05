#include<bits/stdc++.h>
using namespace std;
bool intersect(int l1, int r1, int l2, int r2) {
    if ((r1 < l2) || (r2 < l1))
        return false;
    return true;
}

pair<int, int> a[211], b[211];
int main() {
    int x, y, n, i, j;
    bool f;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x >> y;
        f = 1;
        for (j = 0; j < i; ++j)
        {
            if (intersect(a[j].first, a[j].second, x, x + y - 1)) {
                f = 0;
                break;
            }
        }

        if (f) {
            a[i] = make_pair(x, x + y - 1);
            b[i] = make_pair(x, x + y - 1);
            continue;
        }

        x = 1;
        sort(a, a + i);

        for (j = 0; j < i; ++j)
        {
            if (intersect(a[j].first, a[j].second, x, x + y - 1)) {
                x = max(a[j].second + 1, x);
            }
        }

        a[i] = make_pair(x, x + y - 1);
        b[i] = make_pair(x, x + y - 1);
    }

    for (i = 0; i < n; ++i) {
        cout << b[i].first << ' ' << b[i].second << "\n";
    }
    return 0;
}
