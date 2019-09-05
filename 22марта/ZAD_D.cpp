#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E18;
ll a[100010], b[100010];
int main()
{
    freopen("jam.in", "r", stdin);
    freopen("jam.out", "w", stdout);
    ll n, m, i, j, x, y, l, r;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%I64d", &b[i]);
    for (i = 0; i < n; i++)
        a[i] = b[i] - a[i];
    cin >> m;
    if ((n < 5010) && (m < 5010))
    {
        for (i = 0; i < n; i++)
            {
                if (a[i] <= 0)
                {
                    b[i] = 0;
                    a[i] = INF;
                }
                else
                    b[i] = -1;
            }

        for (i = 0; i < m; i++)
        {
            scanf("%I64d%I64d%I64d%I64d", &l, &r, &x, &y);
            for (j = l - 1; j < r; j++)
            {
                a[j] = a[j] - (x + y * (j - l + 1));
                //cout << j << ' ' << a[j] << endl;
                if (a[j] <= 0)
                {
                    a[j] = INF;
                    b[j] = i + 1;
                }
            }
        }

        for (i = 0; i < n; i++)
            printf("%I64d ", b[i]);
        return 0;
    }

    for(;;);
    return 0;
}

/*
5
5 4 4 2 1
7 7 4 7 7
3
1 2 2 0
2 5 1 1
3 4 2 2
*/
