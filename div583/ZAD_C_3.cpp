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
    size_t indCl = s.find(')');
    if (indCl == string::npos) {
        cout << "No\n";
        return 0;
    }
    s.erase(indCl, size_t(1));
    s.push_back(')');

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (s[i] == '(') ? 1 : -1;
        if (sum < 0) {
            cout << "No\n";
            return 0;
        }
    }

    if (sum == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
