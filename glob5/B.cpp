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
const ll DL = 100010;

int a[DL], b[DL];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        b[x] = i;
    }

    int ans = 0, mx = -1;
    for (int i = 0; i < n; ++i) {
        if (b[a[i]] < mx) {
            ++ans;
        } else {
            mx = b[a[i]];
        }
    }

    cout << ans << '\n';
}