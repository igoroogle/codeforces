#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E18;
int bits[1027], bl[3010], br[3010], ans[3010];
bool a[1027];
int main()
{
    //freopen("connections.in", "r", stdin);
    //freopen("connections.out", "w", stdout);
    int i, j, n, k, p, x;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d%d", &bl[i], &br[i]);
    for (p = 0; p < (1 << n); p++)
    {
        a[p] = 1;
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (((1 << i) & p) && ((1 << j) & p))
                {
                    if (!(((bl[i] > bl[j]) && (bl[i] < br[j]) && (br[i] > br[j])) || ((bl[j] > bl[i]) && (bl[j] < br[i]) && (br[j] > br[i]))))
                        a[p] = 0;
                }
    }

    for (p = 0; p < (1 << n); p++)
    {
        i = p;
        j = 0;
        while (i > 0)
        {
            j += i % 2;
            i /= 2;
        }

        bits[p] = j;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < (1 << n); j++)
            if ((a[j]) && (j & (1 << i)))
                ans[i] = max(ans[i], bits[j]);
    cin >> k;
    for (i = 0; i < k; i++)
    {
        scanf("%d", &x);
        x--;
        printf("%d\n", ans[x]);
    }
    return 0;
}


/*
2 1
Russia Russia go go go
Russia Russia lets go
*/
