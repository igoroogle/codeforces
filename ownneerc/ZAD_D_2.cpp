#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2000000010;
set< pair<ll, ll> > t;
ll
int main()
{
    freopen("cakes.in", "r", stdin);
    freopen("cakes.out", "w", stdout);
    ll sum = 0, tim, n, i, kol = 0, mx = 0, xx, tt, kr = 0;
    cin >> n >> tim;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &xx, &tt);
        sum += xx - kr;
        kr = xx;
        while ((!t.empty()) && (sum > tim))
        {
            sum -= t.begin() -> first;
            kol--;
            t.erase(t.begin());
        }

        if (sum + tt <= tim)
        {
            kol++;
            t.insert(make_pair(tt, i));
            sum += tt;
        }
        else if (tt < t.begin() -> first)
        {

            sum -= t.begin() -> first;
            t.erase(t.begin());
            t.insert(make_pair(tt, i));
            sum += tt;
        }
        if (sum <= tim)
            mx = max(kol, mx);
    }
    cout << mx << endl;
    return 0;
}
