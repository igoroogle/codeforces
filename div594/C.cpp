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
const ll MOD = 1E9 + 7;
const int LEN = 100010;

ll dp[LEN];

int main() {
    ios_base::sync_with_stdio(0);
    dp[0] = 1;
    dp[1]= 2;
    for (int i = 2; i < LEN; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    int n, m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
    }

    if (m == 1) {
        cout << (dp[n - 1] * ll(2)) % MOD << '\n';
        return 0;
    } else if (n == 2) {
        cout <<
    }

    ll ans =
    ans = (dp[n - 2] * dp[m - 2]) % MOD;
    ans = (ans * ll(4)) % MOD;
    cout << ans << '\n';
}