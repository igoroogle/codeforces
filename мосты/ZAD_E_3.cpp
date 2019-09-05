#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a[100010], b[100010];
map <pair<int, int>, bool> t, ts;
int tout[100010], color[100010], type[100010], r1[100010], r2[100010], gip[100010], ans[100010], sum = 0, sum2 = 0;
void dfs1(int v);
void dfs2(int v);
void dfs3(int v);
int main()
{
    freopen("firesafe.in", "r", stdin);
    freopen("firesafe.out", "w", stdout);
    int n, m, i, x, y, v,ss = 0, kol = 0;
    cin >> n >> m;
    for (i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            x--;
            y--;
            if (x == y)
                continue;
            if (t[make_pair(x, y)])
                continue;
            b[x].push_back(y);
            a[y].push_back(x);
            t[make_pair(x, y)] = 1;
        }

    for (i = 0; i < n; i++)
        if (!color[i])
            dfs1(i);

    for (i = 0; i < n; i++)
        color[i] = 0;
    for (i = sum - 1; i >= 0; i--)
        if (!color[tout[i]])
            {
                dfs2(tout[i]);
                sum2++;
            }

    for (i = 0; i < n; i++)
        dfs3(i);
    for (i = 0; i < n; i++)
        if (!gip[type[i]])
        {
            gip[type[i]] = 1;
            ans[kol] = i + 1;
            kol++;
        }
    cout << kol << endl;

    for (i = 0; i < kol; i++)
            printf("%d ", ans[i]);
    return 0;
}

void dfs1(int v)
{
    int i;
    color[v] = 1;
    for (i = 0; i < a[v].size(); i++)
    {
        if (!color[a[v][i]])
            dfs1(a[v][i]);
    }
    color[v] = 2;
    tout[sum] = v;
    sum++;
}

void dfs2(int v)
{
    int i;
    color[v] = 1;
    type[v] = sum2;
    for (i = 0; i < b[v].size(); i++)
    {
        if (!color[b[v][i]])
            dfs2(b[v][i]);
    }
    color[v] = 2;
}

void dfs3(int v)
{
    int i;
    for (i = 0; i < b[v].size(); i++)
        if (type[b[v][i]] != type[v])
            gip[type[v]]++;
}
