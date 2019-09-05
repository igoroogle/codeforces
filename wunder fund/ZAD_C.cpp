#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 2E9;
pair< pair<ll, ll>, ll> dot[100010];
pair<pair<ld, ll>, pair<ll, ll>> ans[100010];
int main()
{
    ll n, i, j, mx = 0, x, y, m = 0, a, b, c;
    pair< pair<ll, ll>, ll> pt = mp(mp(INF, INF), INF);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        dot[i] = mp(mp(y, x), i);
        pt = min(pt, dot[i]);
    }

    for (i = 0; i < n; i++)
        swap(dot[i].x.x, dot[i].x.y);

    swap(pt.x.x, pt.x.y);
    m = 0;
    for (i = 0; i < n; i++)
        if (dot[i] != pt)
            ans[m++] = mp(mp(atan2(ld(dot[i].x.y - pt.x.y), ld(dot[i].x.x - pt.x.x)), dot[i].x.y),mp(dot[i].x.x, dot[i].y));
    n = m;
    sort(ans, ans + n);
    a = pt.y + 1;
    b = ans[0].y.y + 1;
    bool f = 1;
    for (i = 1; i < n; i++)
        if (ans[i].x.x != ans[i - 1].x.x)
        {
            c = ans[i].y.y + 1;
            f = 0;
            break;
        }
    if (f)
        for(;;);
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
