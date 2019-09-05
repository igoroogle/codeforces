#include <bits/stdc++.h>
using namespace std;
const int DL = 200010;
int ranks[DL], jump[DL], parent[DL];
int getroot(int v);
void unionv(int u, int v);
void union_interval(int u, int v);
int main()
{
    int n, q, i, t, x, y;
    cin >> n >> q;
    for (i = 0; i < n; i++)
    {
        ranks[i] = 1;
        jump[i] = i;
        parent[i] = -1;
    }

    for (i = 0; i < q; i++)
    {
        scanf("%d%d%d", &t, &x, &y);
        x--;
        y--;
        if (t == 1)
            unionv(getroot(x), getroot(y));
        else if (t == 2)
            union_interval(x, y);
        else
        {
            if (getroot(x) == getroot(y))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
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

void union_interval(int u, int v)
{
    if (u == v)
        return;
    if (jump[u] >= v)
        return;
    if (jump[u] != u)
    {
        union_interval(jump[u], v);
        jump[u] = jump[jump[u]];
        return;
    }
    union_interval(u + 1, v);
    jump[u] = jump[u + 1];
    unionv(getroot(u), getroot(u + 1));
}
