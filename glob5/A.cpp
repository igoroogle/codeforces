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
int a[14010];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    int c1 = 0, c2 = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (abs(a[i]) % 2) {
            if (a[i] > 0) {
                ++c1;
            } else {
                ++c2;
            }
        }
    }

    c1 /= 2;
    c2 /= 2;
    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) % 2) {
            if (a[i] > 0) {
                if (c1 > 0) {
                    --c1;
                    a[i] = a[i] / 2 + 1;
                } else {
                    a[i] /= 2;
                }
            } else {
                if (c2 > 0) {
                    --c2;
                    a[i] = abs(a[i]) / 2 + 1;
                } else {
                    a[i] = abs(a[i]) / 2;
                }
                a[i] = -a[i];

            }
        } else {
            if (a[i] < 0) {
                a[i] = abs(a[i]) / 2;
                a[i] = -a[i];
            } else {
                a[i] /= 2;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << '\n';
    }
}