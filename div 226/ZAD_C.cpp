#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 10000003;
string s;
int pr[DL];
int a[1000010];
ll sum[DL];
int main()
{
    int i, j, p, n, x, m, l, r, cnt = 1;
    for (i = 0; i < DL; i++)
        {
            if (i % 2)
                pr[i] = i;
            else
                pr[i] = 2;
        }
    p = 3;
    while (p < DL)
    {
        if (pr[p] == p)
        {
            cnt++;
            for (i = p + p; i < DL; i += p)
                {
                    if (p < pr[i])
                        pr[i] = p;
                }
        }
        p += 2;
    }

    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        p = -1;
        j = a[i];
        while (j > 1)
        {
            if (pr[j] != p)
                sum[pr[j]]++;
            p = pr[j];
            j /= pr[j];
        }
    }
    for (i = 1; i < DL; i++)
        sum[i] = sum[i - 1] + sum[i];

    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        r = min(10000000, r);
        if (r < l) printf("0\n");
        else printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}
