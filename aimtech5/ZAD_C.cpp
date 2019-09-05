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
pair<pair<int, int>, pair<int, int>> a[200010], b[200010], c[200010];
bool use1[200010], use2[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, x1, y1, x2, y2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = mp(mp(x1, x2), mp(y1, y2));
    }
    sort(a, a + n);

    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (use1[i - 1]) {
            use1[i] = true;
            continue;
        }

        b[i].x.x = max(a[i].x.x, b[i - 1].x.x);
        b[i].x.y = min(a[i].x.y, b[i - 1].x.y);
        b[i].y.x = max(a[i].y.x, b[i - 1].y.x);
        b[i].y.y = min(a[i].y.y, b[i - 1].y.y);
        if (b[i].x.x > b[i].x.y || b[i].y.x > b[i].y.y) {
            use1[i] = true;
        }
    }

    c[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (use2[i + 1]) {
            use2[i] = true;
            continue;
        }

        c[i].x.x = max(a[i].x.x, c[i + 1].x.x);
        c[i].x.y = min(a[i].x.y, c[i + 1].x.y);
        c[i].y.x = max(a[i].y.x, c[i + 1].y.x);
        c[i].y.y = min(a[i].y.y, c[i + 1].y.y);
        if (c[i].x.x > c[i].x.y || c[i].y.x > c[i].y.y) {
            use2[i] = true;
        }
    }

    if (!use1[n - 2]) {
        cout << b[n - 2].x.x << ' ' << b[n - 2].y.x << '\n';
        return 0;
    }

    if (!use2[1]) {
        cout << c[1].x.x << ' ' << c[1].y.x << '\n';
        return 0;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (use1[i - 1] || use2[i + 1]) {
            continue;
        }

        pair<pair<int, int>, pair<int, int>> d;
        d.x.x = max(b[i - 1].x.x, c[i + 1].x.x);
        d.x.y = min(b[i - 1].x.y, c[i + 1].x.y);
        d.y.x = max(b[i - 1].y.x, c[i + 1].y.x);
        d.y.y = min(b[i - 1].y.y, c[i + 1].y.y);
        if (d.x.x > d.x.y || d.y.x > d.y.y) {
            continue;
        }

        cout << d.x.x << ' ' << d.y.x << '\n';
        return 0;
    }
}
