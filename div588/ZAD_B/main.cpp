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

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    string s;
    cin >> n >> k >> s;

    if (n == 1) {
        if (k > 0) {
            cout << "0\n";
        } else {
            cout << s << '\n';
        }
        return 0;
    }

    if ((s[0] > '1') && (k > 0)) {
        s[0] = '1';
        --k;
    }

    for (int i = 1; i < n; ++i) {
        if (k == 0) {
            break;
        }
        if (s[i] > '0') {
            s[i] = '0';
            --k;
        }
    }

    cout << s << '\n';
}