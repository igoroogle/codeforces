#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
const int LEN = 800002;
const int ELEN = 11;

vector<int> t[LEN];
int a[LEN];

void combine(vector<int>& ans, vector<int>& a, vector<int>& b) {
    if (a.empty()) {
        ans = b;
        return;
    } else if (b.empty()) {
        ans = a;
        return;
    }

    ans.resize(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
    if (ELEN < int(ans.size())) {
        ans.resize(ELEN);
    }
}

void build (int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v].resize(1);
        t[v].front() = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        combine(t[v], t[v*2], t[v * 2 + 1]);
    }
}

void update (int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v].resize(1);
        t[v].front() = new_val;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        combine(t[v], t[v*2], t[v * 2 + 1]);
    }
}

void get (vector<int>& ans, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return;

    if (l == tl && r == tr) {
        ans = t[v];
        return;
    }

    int tm = (tl + tr) / 2;
    vector<int> lefAr, rigAr;
    get(lefAr, v*2, tl, tm, l, min(r,tm));
    get(rigAr, v*2+1, tm+1, tr, max(l,tm+1), r);
    combine(ans, lefAr, rigAr);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(a, 1, 1, n);
    while(m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int ind, x;
            cin >> ind >> x;
            update(1, 1, n, ind, x);
        } else {
            int l, r;
            cin >> l >> r;
            vector<int> ans;
            get(ans, 1, 1, n, l, r);

            if (int(ans.size()) < 2) {
                cout << "-1\n";
                continue;
            }

            vector<int>pos;
            pos.assign(ELEN, -1);
            bool f = false;
            for (size_t i = 0; i < ans.size(); ++i) {
                int cur = ans[i];
                int j = 0;
                while (cur > 0) {
                    if (cur % 10 != 0) {
                        if (pos[j] == -1) {
                            pos[j] = i;
                        } else {
                            cout << ans[pos[j]] + ans[i] << '\n';
                            //cout << ans[pos[j]]  << ' ' << ans[i] << ' ' << pos[j] << ' ' << i << '\n';
                            f = true;
                            break;
                        }
                    }
                    ++j;
                    cur /= 10;
                }

                if (f) {
                    break;
                }
            }

            if (!f) {
                cout << "-1\n";
            }
        }
    }
}
