#include <bits/stdc++.h>
using namespace std;
const int DL = 10010;
struct trio
{
    int x, y, z;
};
int ranks[DL], parent[DL], val[DL];
trio a[DL];
int getroot(int v);
void unionv(int u, int v);
bool comp(trio a, trio b);
int main()
{
    int n, m, i, j, x, y, z, u, v, k = 0, sum = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        ranks[i] = 1;
        parent[i] = -1;
        scanf("%d", &val[i]);
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        x--;
        y--;
        a[i].x = x;
        a[i].y = y;
        a[i].z = z;
    }

    sort(a, a + m, comp);
    for (i = 0; i < m; i++)
    {
        u = getroot(a[i].x);
        v = getroot(a[i].y);
        if (u != v)
        {
            sum += a[i].z;
            unionv(u, v);
            k++;
        }
    }
    if (k != n - 1)
        cout << -1 << endl;
    else
        cout << sum << endl;
    return 0;
}

int getroot(int v)
{
    if (parent[v] == -1)
        return v;
    parent[v] = getroot(parent[v]);
    return parent[v];
}

void unionv(int u, int v)
{
    if (u == v)
        return;
    if (ranks[u] > ranks[v])
        parent[v] = u;
    else if (ranks[v] > ranks[u])
        parent[u] = v;
    else
    {
        parent[v] = u;
        ranks[u]++;
    }
}

bool comp(trio a, trio b)
{
    return a.z < b.z;
}
