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
const ll MOD = 998244353;
const int LEN = 300010;

int a[LEN], b[LEN];
ll f[LEN];
pii ar[LEN];

void precalc_fac(int n) {
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] * ll(i)) % MOD;
    }
}

template <typename T> ll go_up(T a[], int n) {
    ll ans = 1;
    int counts = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            ans = (ans * f[counts]) % MOD;
            counts = 1;
        } else {
            ++counts;
        }
    }
    ans = (ans * f[counts]) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    precalc_fac(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ar[i] = mp(a[i], b[i]);
    }

    ll left = 0, right = 0, both = 0;
    sort(a, a + n);
    left = go_up(a, n);
    sort(b, b + n);
    right = go_up(b, n);
    sort(ar, ar + n);

    bool flag = true;
    for (int i = 1; i < n; ++i) {
        if (ar[i].y < ar[i - 1].y) {
            flag = false;
            break;
        }
    }

    if (flag) {
        both = go_up(ar, n);
    }

    cout << (f[n] + MOD * ll(2) - left - right + both) % MOD << '\n';
}