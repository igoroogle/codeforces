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
const int ST = 19;
int rt[300002], n;
pair<int, int> tmn[2000002], tmx[2000002];
int pl[ST][300002], pr[ST][300002];

void build(int v, int l, int r) {
    if (l == r) {
        tmn[v] = mp(max(l - rt[l], 0), l);
        tmx[v] = mp(min(l + rt[l], 3 * n), l);
        return;
    }

    int m = (l + r) >> 1;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    tmn[v] = min(tmn[v + v], tmn[v + v + 1]);
    tmx[v] = max(tmx[v + v], tmx[v + v + 1]);
}

pair<int, int> getMin(int v, int l, int r, int l1, int r1) {
    if (l1 > r1) {
        return mp(3 * n, 3 * n);
    }

    if ((l == l1) && (r == r1)) {
        return tmn[v];
    }

    int m = (l + r) >> 1;
    return min(getMin(v + v, l, m, l1, min(r1, m)), getMin(v + v + 1, m + 1, r, max(m + 1, l1), r1));
}

pair<int, int> getMax(int v, int l, int r, int l1, int r1) {
    if (l1 > r1) {
        return mp(0, 0);
    }

    if ((l == l1) && (r == r1)) {
        return tmx[v];
    }

    int m = (l + r) >> 1;
    return max(getMax(v + v, l, m, l1, min(r1, m)), getMax(v + v + 1, m + 1, r, max(m + 1, l1), r1));
}

bool check(int ind, int x) {
    if (x == 0) {
       if (n == 1) {
            return false;
       } else {
            return true;
       }
    }

    if (x == n) {
        return false;;
    }

    int lf = ind, y = x - 1, rf = ind;
    for (int i = 0; i < ST; ++i) {
        if ((1 << i) & y) {
            lf = pl[i][lf];
            rf = pr[i][rf];
        }
    }

    lf = max(0, lf - rt[lf]);
    rf = min(3 * n, rf + rt[rf]);
    return (rf - lf + 1 < n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        rt[i] = x;
        rt[n + i] = x;
        rt[2 * n + i] = x;
    }
    build(1, 1, 3 * n);

    for (int i = 1; i <= 3 * n; ++i) {
        if (i - rt[i] <= 0) {
            pl[0][i] = 0;
        } else {
            pl[0][i] = getMin(1, 1, 3 * n, i - rt[i], i).y;
        }

        if (i + rt[i] >= 3 * n) {
            pr[0][i] = 3 * n;
        } else {
            pr[0][i] = getMax(1, 1, 3 * n, i, i + rt[i]).y;
        }
    }

    for (int i = 1; i < ST; ++i) {
        for (int j = 0; j <= 3 * n; ++j) {
            pl[i][j] = pl[i - 1][pl[i - 1][j]];
            pr[i][j] = pr[i - 1][pr[i - 1][j]];
        }
    }


    for (int i = n + 1; i <= n + n; ++i) {
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(i, m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (i == 150) {
            cout << endl;
            cout << l << endl;
            cout << i << ' ' << rt[i] << ' ' << rt[i + 1] << ' ' << rt[i + 2] << ' ' << rt[i - 1] << ' ' << rt[i - 2] << endl;
            cout << pl[0][i] << ' ' << pr[0][i] << endl;
            cout << pl[0][i] - rt[pl[0][i]] << ' ' << pr[0][i] + rt[pr[0][i]] << endl;
            cout << pl[1][i] - rt[pl[1][i]] << ' ' << pr[1][i] + rt[pr[1][i]] << endl;
            return 0;
        }
        cout << l << ' ';
    }
}
