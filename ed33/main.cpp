#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    int n, a = 1, b = 2, c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if ((c != a) && (c != b)) {
            cout << "NO\n";
            return 0;
        }

        if (c == b) {
            swap(a, b);
        }
        b = 6 - a - b;
    }
    cout << "YES\n";
    return 0;
}