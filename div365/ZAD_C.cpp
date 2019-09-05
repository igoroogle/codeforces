#include<bits/stdc++.h>
#define y first
#define x second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ll, ll> a[10010];
int main()
{
    ll n, w, v, u, i, x, y;
    ld ans, t;
    cin >> n >> w >> v >> u;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        a[i] = mp(y, x);
    }

    //sort(a, a + n);
    bool f = 1;
    for (i = 0; i < n; i++)
    {
        if (a[i].x * u < a[i].y * v)
        {
            f = 0;
            break;
        }
    }

    if (f)
    {
        cout << fixed << setprecision(8) << ld(w) / ld(u) << endl;
        return 0;
    }

    ans = ld(0);
    x = a[0].x;
    y = a[0].y;
    for (i = 0; i < n; i++)
        if ((a[i].x > x) || ((a[i].x == x) && (a[i].y > y)))
        {
            x = a[i].x;
            y = a[i].y;
        }
    t = max(ld(x) / ld(v), ld(y) / ld(u));
    t += (ld(w) - ld(y)) / ld(u);
    cout << fixed << setprecision(8) << t << endl;
    return 0;
}
