#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 103;
vector<int> a[DL];
bool use[DL];
int color[DL], tin[DL], fup[DL], sum = 0;
void dfs1(int v, int p);
void dfs2(int v, int val);
int main()
{
    int n, m, i, x, y, sm = 0;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs1(0, -1);
    for (i = 0; i < n; i++)
        if (!use[i])
        {
            cout << "NO\n";
            return 0;
        }

    sum = 0;
    for (i = 0; i < n; i++)
        use[i] = 0;
    dfs2(0, 0);
    for (i = 0; i < n; i++)
        if (color[i] > 2)
            sm++;
    if (n == m)
        cout << "FHTAGN!\n";
    else
        cout << "NO\n";
    return 0;
}

void dfs1(int v, int p)
{
    use[v] = 1;
    tin[v] = sum++;
    fup[v] = tin[v];
    int i;
    for (i = 0; i < a[v].size(); i++)
    {
        if (!use[a[v][i]])
        {
            dfs1(a[v][i], v);
            fup[v] = min(fup[v], fup[a[v][i]]);
        }
        else if (a[v][i] != p)
            fup[v] = min(fup[v], tin[a[v][i]]);
    }
}

void dfs2(int v, int val)
{
    use[v] = 1;
    color[val]++;
    int i;
    for (i = 0; i < a[v].size(); i++)
        if (!use[a[v][i]])
        {
            if (fup[a[v][i]] <= tin[v])
                dfs2(a[v][i], val);
            else
            {
                sum++;
                dfs2(a[v][i], sum);
            }
        }
}
