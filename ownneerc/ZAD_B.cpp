#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2000000010;
ll a[300010], sum[300010];
int main()
{
    freopen("longqueue.in", "r", stdin);
    freopen("longqueue.out", "w", stdout);
    ll n, m, x, i, l, r, typ, val;
    cin >> n >> x;
    l = 1;
    r = n;
    sum[0] = 0;
    for (i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
            if (a[i] >= x)
                a[i] = 1;
            else
                a[i] = 0;
            sum[i] = sum[i - 1] + a[i];
        }
    cin >> m;
    for(i = 0; i < m; i++)
    {
        scanf("%I64d", &typ);
        if (typ == 1)
        {
            scanf("%I64d", &val);
            r++;
            if (val >= x)
                a[r] = 1;
            else
                a[r] = 0;
            sum[r] = sum[r - 1] + a[r];
        }
        else if (typ == 2)
            l++;
        else
        {
            scanf("%I64d", &val);
            printf("%I64d\n", sum[l + val - 1] - sum[l - 1]);
        }
    }
    return 0;
}
