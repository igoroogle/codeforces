#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll x[400010];
pair<ll, ll> a[400010];
ll d[1200100];
set< pair<ll, ll> > tt;
int main()
{
    ll n, m, i, j, u, t, ans = 0;
    pair<ll, ll> dd;
    cin >> n >> m;

    for (i = 0; i < n; i++)
        scanf("%I64d", &x[i]);
    sort(x, x + n);

    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &u, &t);
        tt.insert(mp(u - t, u + t));
    }



    for (i = 0; i < n; i++)
    {
        while (tt.begin() != tt.end())
        {
            dd = *tt.begin();
            tt.erase(*tt.begin());
            if (dd.x == x[i])
            {
                ans++;
                break;
            }

            if (dd.x > x[i])
            {
                tt.insert(dd);
                break;
            }

            if (x[i] <= dd.y)
            {
                dd.x = x[i];
                tt.insert(dd);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
