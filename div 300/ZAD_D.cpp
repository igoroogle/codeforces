#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int n,p;

bool prov(int x1, int y1)
{
    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n) return true;
    return false;
}

bool prov1(int x1, int y1)
{
    if (x1 >= 0 && x1 < n * 2 - 1 && y1 >= 0 && y1 < n * 2 - 1)
        return true;
    else
        return false;
}

int main()
{
    int i, j, x, y, sum = 0, kol = 0, mark[123][123] = {0}, xx[10100], yy[10100], k = 0, kk = 0, qq, rr;
    bool er = false;
    char s[123][123], ss[200][200];
    cin >> n;
    rr = 1;
    for (i = 0; i < n; i++)
        cin >> s[i];

    for (x = -n; x <= n; x++)
        for (y = -n; y <= n; y++)
        {
                p = 0;
                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        if (s[i][j] == 'o' && prov(i + x, j + y) && s[i + x][j + y] == '.')
                            p++;



                if (p == 0)
                {
                    for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        if (s[i][j] == 'o' && prov(i + x, j + y))
                            mark[i + x][j + y] = 1;
                    k++;
                    xx[k] = x;
                    yy[k] = y;
                }
        }

    for (i = 0; i < 2 * n - 1; i++)
        for (j = 0; j < 2 * n - 1; j ++)
            ss[i][j] = '.';


    for (i = 0; i < n; i++)
        for (j = 0; j < n; j ++)
            if (s[i][j] == 'x' && !mark[i][j])
                k = 0;

    ss[n - 1][n - 1] = 'o';
    for (i = 1; i <= k; i++)
    {
        if (prov1((n - 1) + xx[i], (n - 1) + yy[i]))
            ss[(n - 1) + xx[i]][(n - 1) + yy[i]] = 'x';
    }
    ss[n - 1][n - 1] = 'o';
    if (k == 0)
        cout << "NO";
    else
    {
        cout << "YES" << endl;;
    for (i = 0; i < 2 * n - 1; i++)
    {
        cout << ss[i];

    cout << endl;
    }
    }

  return 0;
}














