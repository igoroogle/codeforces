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

int a[26];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        ++a[c - 'a'];
    }

    int ones = min(min(a['o' - 'a'], a['n' - 'a']), a['e' - 'a']);
    a['o' - 'a'] -= ones;
    a['n' - 'a'] -= ones;
    a['e' - 'a'] -= ones;

    int zeros = min(min(a['z' - 'a'], a['e' - 'a']), min(a['r' - 'a'], a['o' - 'a']));
    for (int i = 0; i < ones; ++i) {
        cout << "1 ";
    }

    for (int i = 0; i < zeros; ++i) {
        cout << "0 ";
    }
}
