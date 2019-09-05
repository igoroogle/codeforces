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
int counts[10];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    n = n * n;
    for (int i = 0; i < n; ++i) {
        for (int j = 9; j >= 0; --j) {
            cout << int(bool((1 << j) & i));
            counts[j] += int(bool((1 << j) & i));
        }
        cout << endl;
    }

    for (int i = 0; i < 10; ++i) {
        cout << i << ' ' << counts[i] << ' ' << counts[i] % 4 << endl;
    }
}
