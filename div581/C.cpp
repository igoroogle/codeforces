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

const int INF = 1E9;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    for (int i = 0; i < n; ++i) {
        d[i].resize(n);
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            d[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           if ((i != j) && (d[i][j] == 0)) {
               d[i][j] = INF;
           }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((d[i][k] < INF) && (d[k][j] < INF)) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    int m;
    cin >> m;
    vector<int> ans;
    int st, nxt;
    cin >> st >> nxt;
    --st;
    --nxt;
    ans.pb(st);
    for (int i = 2; i < m; ++i) {
        int last;
        cin >> last;
        --last;
        if (d[st][last] != d[st][nxt] + d[nxt][last]) {
            ans.pb(nxt);
            st = nxt;
        }
        nxt = last;
    }

    ans.pb(nxt);

    cout << ans.size() << '\n';
    for (auto cur: ans) {
        cout << cur + 1 << ' ';
    }
}