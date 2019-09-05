#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
int a[DL], b[DL], d[DL], ans[DL];
int main()
{
    int n, m, c, val, i;
    cin >> n >> m >> c;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for (i = 1; i <= m; i++)
        d[i] = (d[i - 1] + b[i]) % c;
    for (i = 1; i <= n; i++)
    {
        ans[i] = a[i] % c;
        val = n - m + 1;
        if (m <= i)
        {
            if (i  <= val)
                ans[i] = (ans[i] + d[m]) % c;
            else
                ans[i] = (ans[i] + d[m] + c - d[i - val]) % c;
        }
        else
        {
            if (val >= i)
                ans[i] = (ans[i] + d[i]) % c;
            else
                ans[i] = (ans[i] + d[i] + c - d[i - val]) % c;
        }
    }
    for (i = 1; i <=n; i++)
        printf("%d ",ans[i]);
    return 0;
}
