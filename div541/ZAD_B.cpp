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

pii both(pii v) {
    int ans = max(v.x, v.y);
    return mp(ans, ans);
}

pii rboth(pii v) {
    int ans = min(v.x, v.y);
    return mp(ans, ans);
}

int get_ans(pii a, pii b) {
    auto v1 = both(a);
    auto v2 = rboth(b);
    if (v1 <= v2) {
        int ans = v2.x - v1.x + 1;
        if (v1 == a) {
            --ans;
        }
        return ans;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    int ans = 0;
    cin >> n;
    pii past = mp(-1, 0);
    for (int i = 0; i < n; ++i) {
        pii val;
        cin >> val.x >> val.y;
        if (past == val) {
            continue;
        }
        ans += get_ans(past, val);
        past = val;
    }
    cout << ans << '\n';
}
