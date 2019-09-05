#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool use[503][503];
char ans[510];
void dfs(int v);
int n;
int main()
{
    int m, u, v, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        ans[i] = 'b';

    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        u--;
        v--;
        use[u][v] = 1;
        use[v][u] = 1;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if ((i != j) && (!use[i][j]) && (ans[i] == 'b'))
            {
                ans[i] = 'a';
                dfs(i);
            }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if ((i != j) && (use[i][j]) && (ans[i] != ans[j]) && (ans[i] != 'b') && (ans[j] != 'b'))
            {
                cout << "No\n";
                return 0;
            }

    cout << "Yes\n";
    for (i = 0; i < n; i++)
        printf("%c", ans[i]);

    return 0;
}

void dfs(int v)
{
    int i;
    for (i = 0; i < n; i++)
        if ((i != v) && (!use[v][i]))
        {
            if (ans[i] != 'b')
            {
                if (ans[i] == ans[v])
                {
                    cout << "No\n";
                    exit(0);
                }
                continue;
            }

            if (ans[v] == 'a')
                ans[i] = 'c';
            else
                ans[i] = 'a';
            dfs(i);
        }
}
