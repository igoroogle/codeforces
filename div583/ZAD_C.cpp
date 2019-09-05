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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0, indOp = -1, indCl = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++sum;
            indOp = i;
        } else {
            --sum;
        }

        if ((sum == -1) && (indCl == -1)) {
            indCl = i;
        }
    }

    if (sum != 0) {
        cout << "No\n";
        return 0;
    } else if (indCl == -1) {
        cout << "Yes\n";
        return 0;
    }

    swap(s[indOp], s[indCl]);
    sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++sum;
        } else {
            --sum;
        }
        if (sum < 0) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}
