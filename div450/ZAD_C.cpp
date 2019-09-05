#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9;
int vl[100010];
int main() {
    ios_base::sync_with_stdio(0);
    int n, i, x, a, b;
    set<int> nx;
    nx.insert(INF);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nx.insert(x);
        a = *nx.upper_bound(x);
        if (a == INF) {
            --vl[x];
            continue;
        }
        b = *nx.upper_bound(a);
        if (b == INF) {
            ++vl[a];
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (vl[i] > vl[ans]) {
            ans = i;
        }
    }
    cout << ans << endl;
}
