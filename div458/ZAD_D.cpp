#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ll DL = 1007;
int t[1048579], a[500010];

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l - 1];
        return;
    }

    int m = (l + r) >> 1;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    t[v] = gcd(t[v + v], t[v + v + 1]);
}

void upd(int v, int l, int r, int ind, int x) {
    if (l == r) {
        t[v] = x;
        return;
    }

    int m = (l + r) >> 1;
    if (ind <= m){
        upd(v + v, l, m, ind, x);
    } else {
        upd(v + v + 1, m + 1, r, ind, x);
    }

    t[v] = gcd(t[v + v], t[v + v + 1]);
}

int get_num(int v, int l, int r, int l1, int r1, int x) {
    if ((r < l1) || (l > r1)) {
        return -1;
    }

    if ((l1 <= l) && (r <= r1)) {
        if (t[v] % x == 0) {
            return -1;
        }

        if (l == r) {
            return l;
        }
    }

    int m = (l + r) >> 1;
    int ans = get_num(v + v, l, m, l1, r1, x);
    if (ans == -1) {
        ans = get_num(v + v + 1, m + 1, r, l1, r1, x);
    }
    return ans;
}

int get(int v, int l, int r, int l1, int r1) {
    if (l1 > r1) {
        return 0;
    }

    if ((r < l1) || (l > r1)) {
        return 0;
    }

    if ((l1 <= l) && (r1 >= r)) {
        return t[v];
    }

    int m = (l + r) >> 1;
    return gcd(get(v + v, l, m, l1, r1), get(v + v + 1, m + 1, r, l1, r1));
}



int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    build(1, 1, n);
    int tp, l, r, x, ind, nm;
    while (q--) {
        cin >> tp;
        if (tp == 1) {
            cin >> l >> r >> x;
            int nm = get_num(1, 1, n, l, r, x);
            if (nm == -1) {
                cout << "YES\n";
                continue;
            }

            if (gcd(get(1, 1, n, l, nm - 1), get(1, 1, n, nm + 1, r)) % x == 0) {
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        } else {
            cin >> ind >> x;
            upd(1, 1, n, ind, x);
        }
    }
}
