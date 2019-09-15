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


int use[110], ar[110];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }

    sort(ar, ar + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            ++ans;
            for (int j = i; j < n; ++j) {
                if (ar[j] % ar[i] == 0) {
                    use[j] = true;
                }
            }
        }
    }

    cout << ans << '\n';
}
