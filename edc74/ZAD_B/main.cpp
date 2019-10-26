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
int a[100010];

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("output.txt", "w", stdout);
    cout << "100000\n";
    /*for (int i = 0; i < 100000; ++i) {
        cout << "1 1\n";
        cout << "1\n";
    }*/

    int ans = 0;
    for (int i = 0; i < (1 << 20); ++i) {
        int zer = 0, ed = 0;
        for (int j = 0; j < 20; ++j) {
            if ((1 << j) & i) {
                ++ed;
            } else {
                ++zer;
            }
        }
        ans += ed * zer;
    }

    cout << ans << endl;
}