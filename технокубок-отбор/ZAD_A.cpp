#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
char a[111][111];
int main()
{
    int n, m, i, j, x, y, sp = 0, pd = 0, s, p;
    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        scanf("\n");
        for (j = 0; j < m; j++)
            scanf("%c", &a[i][j]);
    }


    x = -1;
    for (i = 0; i < n; i++)
            if (a[i][0] == '*')
            {
                x = i;
                break;
            }


    for (i = 1; i < m; i++)
    {
        //cout << x << endl;
        s = 0;
        while (a[x][i] == '.')
        {
            s++;
            x++;
        }

        if (s > 0)
        {
            sp = max(sp, s);
            continue;
        }

        p = 0;
        while ((x > 0) && (a[x - 1][i] == '*'))
        {
            p++;
            x--;
        }

        pd = max(pd, p);
    }

    cout << pd << ' ' << sp << endl;
    return 0;
}
