#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
const int INF = 1E9 + 3;

int ans[300010];
set<pair<int, int>> t[300010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, pr, a, b, w, answ = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        t[i].insert(mp(INF, -i));
    }

    for (int i = n; i < n + n; ++i) {
        cin >> a >> b >> w;
        --a;
        --b;
        pr = -(t[a].lower_bound(mp(-w, INF))->y);
        if (pr == abs(INF)) {
            for(;;);
        }
        ans[i] = ans[pr] + 1;
        answ = max(answ, ans[i]);
        t[b].insert(mp(-w, -i));
    }
    cout << answ << endl;
}
