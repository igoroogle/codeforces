#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 400003;
const ll DL2 = 17;
struct interval
{
    bool tbit[DL];
    ll tsum[DL], tans[DL];
    void build(bool a[], ll v, ll l, ll r)
    {
        if (l == r)
        {
            tbit[v] = a[l];
            tsum[v] = ll(a[l]);
            tans[v] = ll(a[l]);
            return;
        }
        else
        {
            ll m, sum1, sum2, sum, ans1, ans2 ,ans;
            bool bit1, bit2, bit;
            m = (l + r) / 2;
            build(a, v + v, l, m);
            build(a, v + v + 1, m + 1, r);
            sum1 = tsum[v + v];
            sum2 = tsum[v + v + 1];
            ans1 = tans[v + v];
            ans2 = tans[v + v + 1];
            bit1 = tbit[v + v];
            bit2 = tbit[v + v + 1];
            sum = sum1 + sum2;
            bit = bit1 & bit2;
            ans = ans2 + sum1 * (r - m);
            if (bit2)
                ans += ans1;
            tbit[v] = bit;
            tsum[v] = sum;
            tans[v] = ans;
        }
    }

    void update(ll v, ll l, ll r, ll ind, bool val)
    {
        if (l == r)
        {
            tbit[v] = val;
            tsum[v] = ll(val);
            tans[v] = ll(val);
            return;
        }
        else
        {
            ll m, sum1, sum2, sum, ans1, ans2 ,ans;
            bool bit1, bit2, bit;
            m = (l + r) / 2;
            if (ind <= m) update(v + v, l, m, ind, val);
            else update(v + v + 1, m + 1, r, ind, val);
            sum1 = tsum[v + v];
            sum2 = tsum[v + v + 1];
            ans1 = tans[v + v];
            ans2 = tans[v + v + 1];
            bit1 = tbit[v + v];
            bit2 = tbit[v + v + 1];
            sum = sum1 + sum2;
            bit = bit1 & bit2;
            ans = ans2 + sum1 * (r - m - 1);
            if (bit2)
                ans += ans1 + sum1;
            tbit[v] = bit;
            tsum[v] = sum;
            tans[v] = ans;
        }
    }
};

bool b[DL2][DL];
interval a[DL2];
int main()
{
    ll n, m, i, j, x, ind, val, ans, ans1, st;
    bool y;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d", &x);
        for (j = 0; j < DL2; j++)
        {
            b[j][i] = bool(x % 2);
            x /= 2;
        }
    }
    for (i = 0; i < DL2; i++)
        a[i].build(b[i], 1, 1, n);
    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &ind, &val);
        ans = 0;
        st = 1;
        for (j = 0; j < DL2; j++)
            {
                a[j].update(1, 1, n, ind, bool(val % 2));
                ans += a[j].tans[1] * st;
                val /= 2;
                st *= 2;
            }
        printf("%I64d\n", ans);
    }
    return 0;
}
