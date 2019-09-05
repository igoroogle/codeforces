#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
char a[103][103];
int main()
{
    int n, m, i, j, x, y, xx, yy;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        scanf("\n");
        for (j = 1; j <= m; j++)
        {
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'S')
            {
                x = i;
                y = j;
            }
        }
    }

    xx = x;
    yy = y;
    for(;;)
    {
        a[x][y] = '.';
        if (a[x - 1][y] == '*')
        {
            printf("U");
            x--;
            continue;
        }


        if (a[x + 1][y] == '*')
        {
            printf("D");
            x++;
            continue;
        }

        if (a[x][y - 1] == '*')
        {
            printf("L");
            y--;
            continue;
        }

        if (a[x][y + 1] == '*')
        {
            printf("R");
            y++;
            continue;
        }

        break;
    }

    if ((xx == x - 1) && (yy == y))
        printf("U\n");
    else if ((xx == x + 1) && (yy == y))
        printf("D\n");
    else if ((xx == x) && (yy == y - 1))
        printf("L\n");
    else if ((xx == x) && (yy == y + 1))
        printf("R\n");

    return 0;
}
