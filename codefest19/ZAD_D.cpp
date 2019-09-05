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
const int DL = 1E6 + 2;
ll t[DL];

void build(int v, int tl, int tr) {
	if (tl == tr)
		t[v] = tl;
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void update(int v, int tl, int tr, int pos) {
	if (tl == tr)
		t[v] = 0;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos);
		else
			update (v*2+1, tm+1, tr, pos);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int get(int v, int tl, int tr, ll sum) {
	if (tl == tr)
		return tl;
	else {
		int tm = (tl + tr) / 2;
		if (t[v * 2] > sum)
			return get(v*2, tl, tm, sum);
		else
			return get(v*2+1, tm+1, tr, sum - t[v * 2]);
	}
}

ll a[200010], ans[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n + 1);
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = get(1, 1, n + 1, a[i]);
        update(1, 1, n + 1, ans[i]);
        //cout << a[i] << ' ' << ans[i] << ' ' << i << endl;
        //cout << t[1] << endl;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
