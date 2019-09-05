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
int main()
{
    ll n, m, i, j, u, t, ans = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        scanf("%I64d", &x[i]);
    sort(x, x + n);

    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &u, &t);
        a[i] = mp(u, t);
    }
    sort(a, a + m);

    i = 0;
    j = 0;
    while ((i < n) && (j < m))
    {
        if (abs(a[j].x - x[i]) <= a[j].y)
        {
            i++;
            j++;
            ans++;
            continue;
        }

        if (x[i] > a[j].x)
        {
            j++;
            continue;
        }

        i++;
    }

    cout << ans << endl;
    return 0;
}
