#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 2000000010;
bool use[113][5], pod[113][4][103];
int bx[1000100], by[1000100];
char a[5][103];
int main()
{
    int n, k, i, j, p, xx, yy, t, l, r, x, y, z, pp;
    bool f;
    //scanf("%d%d", &n, &k);
    cin >> n >> k;
    t = n + 10;
    for (i = 0; i < 3; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    xx = -1;
    yy = -1;
    for (i = 0; i < 3; i++)
        if ((a[i][0] != '.') && (a[i][1] == '.') && (a[i][0] == 's'))
        {
            xx = i;
            yy = 0;
            break;
        }
    if (xx == -1)
    {
        printf("NO\n");
        return 0;
    }

    for (p = 0; p < t; p++)
        for (i = 0; i < 3; i++)
            for (j = 0; j < n; j++)
                pod[p][i][j] = 0;

    for (i = 0; i < 3; i++)
        for (j = 0; j < n; j++)
            if ((i != xx) && (j != yy) && (a[i][j] != '.'))
                pod[0][i][j] = 1;
    for (p = 1; p < t; p++)
        for (i = 0; i < 3; i++)
            for (j = 0; j < n; j++)
                if ((j + 2 < n) && (pod[p - 1][i][j  + 2]))
                    pod[p][i][j] = 1;
    l = 0;
    r = 0;
    bx[0] = xx;
    by[0] = yy;

    if ((pod[0][xx][yy]) || (pod[1][xx][yy]))
    {
        printf("NO\n");
        return 0;
    }

    f = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < n; j++)
            use[i][j] = 0;
    while (l <= r)
    {
        x = bx[l];
        y = by[l];
        l++;
        if (y  == n - 1)
        {
            f = 1;
            break;
        }
        if ((!pod[y][x][y + 1]) && (!pod[y + 1][x][y + 1]))
        {
            if (!use[x][y + 1])
            {
                r++;
                use[x][y + 1] = 1;
                bx[r] = x;
                by[r] = y + 1;
            }
        }

        if ((x - 1 >= 0) && (!pod[y][x - 1][y + 1]) && (!pod[y + 1][x - 1][y + 1]))
        {
            if (!use[x - 1][y + 1])
            {
                r++;
                use[x - 1][y + 1] = 1;
                bx[r] = x - 1;
                by[r] = y + 1;
            }
        }

        if ( (x + 1 < 3) && ((!pod[y][x + 1][y]) && (!pod[y + 1][x + 1][y + 1])))
        {
            if (!use[x + 1][y + 1])
            {
                r++;
                use[x + 1][y + 1] = 1;
                bx[r] = x + 1;
                by[r] = y + 1;
            }
        }
    }
    if (f)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
