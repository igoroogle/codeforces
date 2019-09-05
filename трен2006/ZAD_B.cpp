#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[110][110];
int dp[2][110][110], ans1[1100000], ans2[1100000];
int func(int x, int y, int t);
int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int n, m, kol = 0, i, j;
    char tr, fl;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            dp[0][i][j] = func(i - 1, j, 1) + func(i, j - 1, 1) - func(i - 1, j - 1, 0);
            if (a[i][j] == 'B')
                dp[0][i][j]++;
            dp[1][i][j] = func(i - 1, j, 0) + func(i, j - 1, 0) - func(i - 1, j - 1, 1);
            if (a[i][j] == 'W')
                dp[1][i][j]++;
        }
    if (dp[0][n - 1][m - 1] < dp[1][n - 1][m - 1])
    {
        if ((n - 1 + m - 1) % 2)
        {
            tr = 'W';
            fl = 'B';
        }

        else
        {
            tr = 'B';
            fl = 'W';
        }
    }
    else
    {
        if ((n - 1 + m - 1) % 2)
        {
            tr = 'B';
            fl = 'W';
        }

        else
        {
            tr = 'W';
            fl = 'B';
        }
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if ((i + j) % 2)
            {
                if (tr != a[i][j])
                {
                    ans1[kol] = i + 1;
                    ans2[kol++] = j + 1;
                }
            }
            else
            {
                if (fl != a[i][j])
                {
                    ans1[kol] = i + 1;
                    ans2[kol++] = j + 1;
                }
            }
        }
    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%d %d\n", ans1[i], ans2[i]);
    return 0;
}

int func(int x, int y, int t)
{
    if ((x < 0) || (y < 0))
        return 0;
    return dp[t][x][y];
}
