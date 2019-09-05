#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> a[200010];
bool dp[6][200010], use[200010];
bool answer(int v, int type, int past);
int main()
{
    int n, m, x, y, i;
    cin >> n;
    m = n - 1;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (answer(0, 0, -1))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

bool answer(int v, int type, int past)
{
    if (use[v])
        return dp[type][v];
    use[v] = 1;
    int i, a1 = 0, b1 = 0, c1 = 0, d1 = 0;
    bool f = 1;
    for (i = 0; i < a[v].size(); i++)
        {
            if (past != a[v][i])
            {
                if (answer(a[v][i], 3, v)) a1++;
                else if (answer(a[v][i], 2, v)) b1++;
                else if (answer(a[v][i], 1, v)) c1++;
                else if (answer(a[v][i], 0, v)) d1++;
                else
                {
                    f = 0;
                    break;
                }
            }
        }
    dp[3][v] = f;
    dp[2][v] = f;
    dp[1][v] = f;
    if ((a1 > 1) || (b1 + c1 + d1 > 0))
        dp[3][v] = 0;
    if ((a1 > 2) || (b1 + c1 + d1 > 0))
        dp[2][v] = 0;
    if ((c1 > 1) || (d1 > 0))
        dp[1][v] = 0;
    if (c1 > 2)
        f = 0;
    if (d1 > 1)
        f = 0;
    if ((d1 == 1) && (a1 + b1 + c1 > 0))
        f = 0;
    dp[0][v] = f;
    return dp[type][v];
}
