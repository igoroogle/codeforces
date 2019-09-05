#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 200010;
const int DL2 = 3002;
const int DL3 = 9012004;
const int INF = 2000000000;
vector <int> reb[DL2][DL2], a[DL2];
bool use[DL2][DL2];
int prv[DL2][DL2], bx[DL3], by[DL3], val[DL2][DL2], n;
void rec(int x, int y);
int main()
{
    int i, j, m, k, x, y, z, l, r, f, s, mx;
    cin >> n >> m >> k;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        if (!use[x][y])
        {
            a[x].push_back(y);
            a[y].push_back(x);
            use[x][y] = 1;
            use[y][x] = 1;
        }
    }

    for (i = 0; i < k; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        reb[x][y].push_back(z);
        reb[z][y].push_back(x);
    }
    for (i = 1; i <= n; i++)
        if (a[i].size() > 0)
            sort(a[i].begin(), a[i].end());

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (reb[i][j].size() > 0)
                sort(reb[i][j].begin(), reb[i][j].end());
    l = 0;
    r = 0;
    bx[0] = 0;
    by[0] = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            use[i][j] = 0;
    use[0][1] = 1;
    while (l <= r)
    {
        x = bx[l];
        y = by[l];
        l++;
        f = 0;
        s = 0;
        while (f < a[y].size())
        {
            while ((s < reb[x][y].size()) && (reb[x][y][s] < a[y][f]))
                s++;
            if (((s == reb[x][y].size()) || (a[y][f] < reb[x][y][s])) && (!use[y][a[y][f]]))
            {
                use[y][a[y][f]] = 1;
                r++;
                bx[r] = y;
                by[r] = a[y][f];
                val[y][a[y][f]] = val[x][y] + 1;
                prv[y][a[y][f]] = x;
            }
            f++;
        }
    }

    mx = INF;
    x = 0;
    y = 0;
    for (i = 1; i <= n; i++)
        if ((use[i][n]) && (val[i][n] < mx))
        {
            mx = val[i][n];
            x = i;
            y = n;
        }
    if (mx == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << mx << endl;
    rec(x, y);
    return 0;
}

void rec(int x, int y)
{
    if (x != 0)
        rec(prv[x][y], x);
    if (y == n)
        printf("%d\n", y);
    else
        printf("%d ", y);
}
