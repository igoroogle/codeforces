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

const int LEN = 300010;

int a[LEN], forw[LEN];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    fill(forw, forw + n, -1);
    for (int i = 0; i < n; ++i) {
        //cout << i << endl;
        cin >> a[i];
        a[n + i] = a[i];
        a[n + n + i] = a[i];
    }

    int l = 0;
    multiset<int> vals;
    vals.insert(0);
    vals.insert(-a[0]);
    for (int i = 1; i < 3 * n; ++i) {
        //cout <<  -(*vals.begin()) << endl;
        while ((l < i) && ((-(*vals.begin()) + 1) / 2 - 1 >= a[i])) {
            forw[l] = i;
            vals.erase(vals.find(-a[l]));
            ++l;
        }
        vals.insert(-a[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (forw[i] == -1) {
            cout << "-1 ";
        } else {
            cout << forw[i] - i << ' ';
        }
    }
}