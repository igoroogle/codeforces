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

const int LEN = 200010;
int a[LEN], b[LEN];

int main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            b[i] = -1;
        }

        for (int i = 0; i < n; ++i) {
            if (b[i] == -1) {
                int ans = 1, cur = a[i];
                while (cur != i) {
                    ++ans;
                    cur = a[cur];
                }

                do {
                    b[cur] = ans;
                    cur = a[cur];
                } while (cur != i);
            }

            cout << b[i] << ' ';
        }
        cout << '\n';
    }
}