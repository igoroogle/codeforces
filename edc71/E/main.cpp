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
    //ios_base::sync_with_stdio(0);
    int ans = 0;
    cout << "? ";
    for (int i = 1; i <= 100; ++i) {
        cout << (i << 7) << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    x &= (1 << 7) - 1;
    ans |= x;


    cout << "? ";
    for (int i = 1; i <= 100; ++i) {
        cout << i << ' ';
    }
    cout << endl;

    cin >> x;
    x >>= 7;
    x <<= 7;
    ans |= x;

    cout << "! " << ans << endl;
}