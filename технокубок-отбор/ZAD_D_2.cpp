#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll x[200010];
pair<ll, ll> a[200010];
ll d[1000100];
map <ll, ll> t1;
set< pair<ll, ll> > tt;
int main()
{
    ll n, m, i, j, u, t, ans = 0, kl = 0, kl2 = 1;
    pair<ll, ll> dd;
    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &x[i]);
        d[kl++] = x[i];
    }
    //sort(x, x + n);

    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &u, &t);
        a[i] = mp(u - t, u + t);
        d[kl++] = u - t;
        d[kl++] = u + t;
    }

    sort(d, d + kl);
    for (i = 1; i < kl; i++)
        if (d[i] != d[i - 1])
        {
            d[kl2++] = d[i];
            t1[d[i]] = ll(kl2 - 1);
        }
    kl = kl2;

    for (i = 0; i < n; i++)
        x[i] = t1[x[i]];
    sort(x, x + n);


    for (i = 0; i < m; i++)
    {
        a[i].x = t1[a[i].x];
        a[i].y = t1[a[i].y];
        tt.insert(a[i]);
    }

    for (i = 0; i < n; i++)
    {
        while (!tt.empty())
        {
            dd = *tt.begin();
            tt.erase(tt.begin());
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

            if (dd.x < dd.y)
            {
                dd.x++;
                tt.insert(dd);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
