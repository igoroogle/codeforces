#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> a[10010];
bool use[100010],dp[4][100010], use2[4][100010];
bool answer(int v, int type);
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
    use[0] = 1;
    if (answer(0, 0))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

bool answer(int v, int type)
{
    if (use2[type][v])
        return dp[type][v];
    use2[type][v] = 1;
    use[v] = 1;
    if (type >= 2)
    {
        int i, ch = 0;
        bool f = 1;
        for (i = 0; i < a[v].size(); i++)
            {
                if ((!use[a[v][i]]))
                {
                    if (!answer(a[v][i], 3))
                    {
                        f = 0;
                        break;
                    }
                    ch++;
                }
            }
        if ((type == 3) && (ch > 1))
            f = 0;
        if ((type == 2) && (ch > 2))
            f = 0;
        dp[type][v] = f;
        return f;
    }
    else if (type == 1)
    {
        int i;
        bool f = 1;
        for (i = 0; i < a[v].size(); i++)
            {
                if ((!use[a[v][i]]))
                {
                    if ((!answer(a[v][i], 2)))
                    {
                        f = 0;
                        break;
                    }
                }
            }
        dp[type][v] = f;
        return f;
    }
    else if (type == 0)
    {
        int i, a1 = 0, b1 = 0, c1 = 0;
        bool f = 1;
        for (i = 0; i < a[v].size(); i++)
            {
                if ((!use[a[v][i]]))
                {
                    if (answer(a[v][i], 3)) a1++;
                    else if (answer(a[v][i], 2)) b1++;
                    else if (answer(a[v][i], 1)) c1++;
                    else
                    {
                        f = 0;
                        break;
                    }
                }
            }
        if (c1 > 2)
            f = 0;
        cout << a1 << ' ' << b1 << ' ' << c1 << endl;
        dp[type][v] = f;
        return f;
    }
}
