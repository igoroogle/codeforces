#include <bits/stdc++.h>
#define make_pair mp
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int typ[510];
bool dfs(int v, int p, int tp);
vector<int> ed[510];
int main()
{
    int n, m, u, v, i, ans = -1;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        u--;
        v--;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    if (dfs(0, -1, 0))
        ans = 0;
    else if (dfs(0, -1, 1))
        ans = 1;
    else if ((dfs(0, -1, 2)))
        ans = 2;
    else
    {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    for (i = 0; i < n; i++)
    {
        if (typ[i] == 0)
            printf("a");
        else if (typ[i] == 1)
            printf("b");
        else
            printf("c");
    }
    cout << endl;
    return 0;
}

bool dfs(int v, int p, int tp)
{
    int i;
    typ[v] = tp;
    for (i = 0; i < ed[v].size(); i++)
        if(ed[v][i] != p)
        {
            if (dfs(ed[v][i], v, tp))
                continue;
            if (tp == 2)
            {
                if (dfs(ed[v][i], v, 1))
                    continue;
                if (dfs(ed[v][i], v, 3))
                    continue;
            }

            if (tp == 1)
            {
                if (dfs(ed[v][i], v, 2))
                    continue;
            }

            if (tp == 3)
            {
                if (dfs(ed[v][i], v, 2))
                    continue;
            }

            return 0;
        }
    return 1;
}
