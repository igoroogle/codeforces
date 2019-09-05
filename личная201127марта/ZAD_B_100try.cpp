#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
ll t[100010];
ll prov(ll a1, ll b1, ll c1);
int main()
{
    freopen("minitrue.in", "r", stdin);
    freopen("minitrue.out", "w", stdout);
    ll i, j, n, x, tm, tx, a = 0, b = 0, c = 0, mx = INF, l, r, m1, m2, ans, vans, vv;
    cin >> n;
    for (i = 1; i <= n; i++)
        {
            scanf("%I64d", &x);
            t[i] = t[i - 1] + x;
        }

    for (i = 1; i <= n - 2; i++)
    {
        l = 1;
        r = n - 1 - i;
        while (r - l > 3)
        {
            m1 = l + (r - l) / 3;
            m2 = r - (r - l) / 3;
            if (prov(i, m1, n - i - m1) < prov(i, m2, n - i - m2))
                l = m1;
            else
                r = m2;
        }
        ans = l;
        vans = prov(i, l, n - i - l);
        for (j = l + 1; j <= r; j++);
        {
            vv = prov(i, j, n - i - j);
            if (vv < vans)
            {
                vans = vv;
                ans = j;
            }
        }
        if (vans < mx)
        {
            mx = vans;
            a = i;
            b = ans;
            c = n - a - b;
        }
    }

    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}

ll prov(ll a1, ll b1, ll c1)
{
    ll i, j, n;
    i = a1;
    j = i + b1;
    n = j + c1;
    ll tm, tx;
    tm = max(t[i], max(t[j] - t[i], t[n] - t[j]));
    tx = min(t[i], min(t[j] - t[i], t[n] - t[j]));
    return tm - tx;
}
