#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef long double ld;
const int DL = 10000;
const int INF = 1E9;
int bx[100010], by[100010];
int vl[103][103], prx[103][103], pry[103][103], n, m, p, q;
bool prv(int x, int y);
void rec(int x, int y);
int main()
{
    int x1, y1, x2, y2, i, j, l, r, x, y, xx, yy;
    for (i = 0; i < 103; i++)
        for(j = 0; j < 103; j++)
            vl[i][j] = INF;

    cin >> n >> m >> p >> q >> x1 >> y1 >> x2 >> y2;
    if (n != m)
        for(;;);

    l = 0;
    r = 0;
    x1--;
    y1--;
    x2--;
    y2--;
    bx[0] = x1;
    by[0] = y1;
    vl[x1][y1] = 0;
    prx[x1][y1] = -1;
    pry[x1][y1] = -1;

    while (l <= r)
    {
        x = bx[l];
        y = by[l];
        l++;


        xx = x - p;
        yy = y - q;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }

        xx = x - p;
        yy = y + q;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }

        xx = x + p;
        yy = y - q;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }

        xx = x + p;
        yy = y + q;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }

        xx = x - q;
        yy = y - p;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }

        xx = x - q;
        yy = y + p;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }

        xx = x + q;
        yy = y - p;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }

        xx = x + q;
        yy = y + p;
        if ((prv(xx, yy)) && (vl[xx][yy] == INF))
        {
            vl[xx][yy] = vl[x][y] + 1;
            prx[xx][yy] = x;
            pry[xx][yy] = y;
            r++;
            bx[r - 1] = xx;
            by[r - 1] = yy;
        }
    }

    if (vl[x2][y2] == INF)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << vl[x2][y2] << endl;
    rec(x2, y2);
    return 0;
}

bool prv(int x, int y)
{
    if ((x < 0) || (x >= n) || (y < 0) || (y >= m))
        return 0;
    return 1;
}


void rec(int x, int y)
{
    if (prx[x][y] != -1)
        rec(prx[x][y], pry[x][y]);

    printf("%d %d\n", x + 1, y + 1);
}
