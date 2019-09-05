#include<bits/stdc++.h>
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
const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, r, buy = INF, sell = -INF;
    cin >> n >> m >> r;
    while (n--) {
        int x;
        cin >> x;
        buy = min(buy, x);
    }

    while (m--) {
        int x;
        cin >> x;
        sell = max(sell, x);
    }

    if (buy >= sell) {
        cout << r << '\n';
    } else {
        cout << r / buy * sell + r % buy << '\n';
    }
}
