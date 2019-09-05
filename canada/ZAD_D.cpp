#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int DL = 800010;
const ll INF = 2E18;
set<pair<ll,ll>> t;
pair<ll, ll> a[300010];
int main() {
    ll n, i, j, x, y, ans = 0, mx = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &x, &y);
        a[i] = mp(x, y);
    }

    sort(a + 1, a + n);
    t.insert(mp(INF, INF
                ));
    ll l = 1;
    while ((l < n) && (a[l].first <= a[0].first))
        ++l;

    mx = l - 1;
    for (i = l; i < n; ++i) {
        t.insert(mp(a[i].second - a[i].first + 1, i));
        //cout << a[i].first << ' ' << a[i].second << ' ' << "get\n";
    }

    ll to;
    for(;;) {
        to = t.begin()->first;
        t.erase(t.begin());
        //cout << to << ' ' << "destroy\n";
        if (a[0].first < to)
            break;
        ++ans;
        a[0].first -= to;
        while (a[l - 1].first > a[0].first)
        {
            --l;
            t.insert(mp(a[l].second - a[l].first + 1, l));
            //cout << a[l].first << ' ' << a[l].second << ' ' << "get\n";
        }
        mx = max(l - 1 + ans, mx);
    }

    cout << n - mx << endl;
}
