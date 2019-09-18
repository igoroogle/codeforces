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

const int LEN = 130;

bool check (int n, int k) {
    if (n <= k) {
        return false;
    }
    int vt = (n - 1) / k + 1;
    return (vt % 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 1; i <= LEN; ++i) {
        for (int j = LEN; j <= LEN + LEN; ++j) {
            cout << int(check(j, i));
        }
        cout << "  -  " << i << endl;
    }
}
