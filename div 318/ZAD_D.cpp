#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 300005;
ll dp1[DL], dp2[DL], nat[DL], nat2[DL], hor[DL], n;
pair <ll, ll> a[DL], b[DL];
ll ans();
int main()
{
    ll q, i, s, x, y;
    cin >> n >> q;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i].first);
        a[i].second = i;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &b[i].first);
        b[i].second = i;
    }

    sort(a, a + n);
    sort(b, b + n);
    reverse(a, a + n);
    reverse(b, b + n);
    for (i = 0; i < n; i++)
    {
        nat[a[i].second] = i;
        nat2[b[i].second] = i;
    }
    for (i = 0; i < n; i++)
        hor[i] = nat2[a[i].second];
    for (i = 0; i < q; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        x = nat[x - 1];
        y = nat[y - 1];
        swap(hor[x], hor[y]);
        printf("%I64d\n", ans());
    }
    return 0;
}

ll ans()
{
    ll s = 0, i, l = 2, val1, val2;
    val1 = 0;
    val2 = 1;
    for (i = 0; i < n; i++)
    {
        if ((val1 < n) && (val1 != hor[i]))
        {
            s += a[i].first * b[val1].first;
            val1 = val2;
            val2 = l;
            l++;
        }
        else
        {
            s += a[i].first * b[val2].first;
            val2 = l;
            l++;
        }
    }
    return s;
}
