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

const int LEN = 200010;

int dp[2][LEN], a[LEN], b[LEN];

int main() {
    ios_base::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    dp[1][0] = c;

    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 1; i < n; ++i) {
        dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + a[i];
        dp[1][i] = min(dp[0][i - 1] + c, dp[1][i - 1]) + b[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << min(dp[0][i], dp[1][i]) << ' ';
    }
}