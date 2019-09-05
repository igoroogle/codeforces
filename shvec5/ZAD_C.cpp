#include <bits/stdc++.h>
using namespace std;
const int DL = 1003;
int ranks[DL], parent[DL], old1[DL], old2[DL], new1[DL], new2[DL];
int getroot(int v);
void unionv(int u, int v);
int main()
{
    int n, i, j, x, y, u, v, kol1 = 0, kol2 = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        ranks[i] = 1;
        parent[i] = -1;
    }

    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        u = getroot(x);
        v = getroot(y);
        if (u == v)
        {
            kol1++;
            old1[kol1 - 1] = x + 1;
            old2[kol1 - 1] = y + 1;
        }
        else
            unionv(u, v);
    }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            u = getroot(i);
            v = getroot(j);
            if (u != v)
            {
                kol2++;
                new1[kol2 - 1] = i + 1;
                new2[kol2 - 1] = j + 1;
                unionv(u, v);
            }
        }
    cout << kol1 << endl;
    for (i = 0; i < kol1; i++)
        printf("%d %d %d %d\n", old1[i], old2[i], new1[i], new2[i]);
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
