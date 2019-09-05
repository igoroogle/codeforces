#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
char a[510][510];
ll sum[510][510], val[510][510], st[510][510], sr[510][510];
int main()
{
    ll n, m, q, i, j, x1, y1, x2, y2, ans;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        scanf("\n");
        for (j = 1; j <= m; j++)
            scanf("%c", &a[i][j]);
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            {
                sr[i][j] = sr[i][j - 1];
                st[i][j] = st[i - 1][j];
                if ((a[i][j] == '.') && (a[i + 1][j] == '.'))
                    sr[i][j]++;
                if ((a[i][j] == '.') && (a[i][j + 1] == '.'))
                    st[i][j]++;
            }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            val[i][j] = 0;
            if ((a[i][j] == '.') && (a[i - 1][j] == '.'))
                val[i][j]++;
            if ((a[i][j] == '.') && (a[i][j - 1] == '.'))
                val[i][j]++;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val[i][j];
        }

    cin >> q;
    while (q--)
    {
        scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
        ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
        ans -= (sr[x1 - 1][y2] - sr[x1 - 1][y1 - 1] + st[x2][y1 - 1] - st[x1 - 1][y1 - 1]);
        printf("%I64d\n", ans);
    }
    return 0;
}
