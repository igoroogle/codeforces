#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2000000100000000000;
ll a[100001], b[101], sum[100002], ans[101][100001];
int main()
{
    freopen("xpart.in", "r", stdin);
    freopen("xpart.out", "w", stdout);
    ll n, x, l, r, val, m, i, j;
    cin >> n >> x;
    sum[0] = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i]);
        sum[i + 1] = sum[i] + a[i];
    }

    for (i = 0; i < x; i++)
        scanf("%I64d", &b[i]);
    for (i = 0; i < n; i++)
    {
        if (sum[n] - sum[i] < b[x - 1])
            ans[x - 1][i] = -INF;
        else
            ans[x - 1][i] = sum[n] - sum[i] - b[x - 1];
    }

    for (i = x - 2; i >= 0; i--)
        for (j = 0; j < n; j++)
        {
            val = sum[j] + b[i];
            l = 0;
            r = n - 1;

            while (l < r)
            {
                m = (l + r) / 2;
                if (val > sum[m + 1])
                    l = m + 1;
                else
                    r = m;
            }

            if ((l == n - 1) || (ans[i + 1][l + 1] == -INF))
                ans[i][j] = -INF;
            else
                ans[i][j] = ans[i + 1][l + 1] + sum[l + 1] - sum[j] - b[i];

        }
    if (ans[0][0] == -INF)
        cout << -1 << endl;
    else
        cout << ans[0][0] << endl;
}
/*
3 2
1 2 3
3 2
*/
