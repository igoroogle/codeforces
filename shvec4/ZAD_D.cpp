#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 1003;
const int DL2 = 100010;
int rank1[DL], rank2[DL], parent1[DL], parent2[DL], num[2][DL][DL], sn1[DL2], sn2[DL2], mr1[DL2], mr2[DL2];
bool use[2][DL][DL];
int getroot1(int v);
int getroot2(int v);
int union_snm1(int u, int v);
int union_snm2(int u, int v);
int main()
{
    int i, j, k, n, m, x, y,sn = 0, mr = 0, cmp, u, v, mor = 0, sng = 0;
    char c;
    cin >> n >> m;
    cmp = n;
    if (!(n % 2))
    {
        cout << -1 << endl;
        return 0;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d%d %c", &x, &y, &c);
        x--;
        y--;
        if (c == 'M')
        {
            if (!num[0][x][y])
                {
                    num[0][x][y] = i + 1;
                    num[0][y][x] = i + 1;
                    mr++;
                    mr1[mr - 1] = x;
                    mr2[mr - 1] = y;
                }
        }
        else
        {
            if (!num[1][x][y])
                {
                    num[1][x][y] = i + 1;
                    num[1][y][x] = i + 1;
                    sn++;
                    sn1[sn - 1] = x;
                    sn2[sn - 1] = y;
                }
        }
    }

    for (i = 0; i < n; i++)
    {
        rank1[i] = 1;
        rank2[i] = 1;
        parent1[i] = -1;
        parent2[i] = -1;
    }

    for (i = 0; i < mr; i++)
    {
        if (cmp == 1)
            break;
        u = getroot1(mr1[i]);
        v = getroot1(mr2[i]);
        if (u == v)
            continue;
        use[0][mr1[i]][mr2[i]] = 1;
        use[0][mr2[i]][mr1[i]] = 1;
        union_snm1(u, v);
        cmp--;
        mor++;
    }

    if (mor + mor < n - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    for (i = 0; i < sn; i++)
    {
        if (cmp == 1)
            break;
        u = getroot1(sn1[i]);
        v = getroot1(sn2[i]);
        if (u == v)
            continue;
        use[1][sn1[i]][sn2[i]] = 1;
        use[1][sn2[i]][sn1[i]] = 1;
        union_snm1(u, v);
        cmp--;
        sng++;
        u = getroot2(sn1[i]);
        v = getroot2(sn2[i]);
        if (u != v)
            union_snm2(u, v);
    }

    for (i = 0; i < sn; i++)
    {
        if (sng + sng == n - 1)
            break;
        if (use[1][sn1[i]][sn2[i]])
            continue;
        u = getroot2(sn1[i]);
        v = getroot2(sn2[i]);
        if (u == v)
            continue;
        use[1][sn1[i]][sn2[i]] = 1;
        use[1][sn2[i]][sn1[i]] = 1;
        sng++;
        union_snm2(u, v);
    }

    if ((sng + sng != n - 1) || (cmp > 1))
    {
        cout << -1 << endl;
        return 0;
    }

    for (i = 0; i < mr; i++)
    {
        if (mor == sng)
            break;
        if (!use[0][mr1[i]][mr2[i]])
            continue;
        u = getroot2(mr1[i]);
        v = getroot2(mr2[i]);
        if (u == v)
        {
            mor--;
            use[0][mr1[i]][mr2[i]] = 0;
            use[0][mr2[i]][mr1[i]] = 0;
        }
        else
            union_snm2(u, v);
    }

    cout << sng + mor << endl;
    for (k = 0; k < 2; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (use[k][i][j])
                {
                    printf("%d ", num[k][i][j]);
                    use[k][i][j] = 0;
                    use[k][j][i] = 0;
                }
    return 0;
}

int getroot1(int v)
{
    if (parent1[v] == -1)
        return v;
    int vl = getroot1(parent1[v]);
    parent1[v] = vl;
    return vl;
}

int getroot2(int v)
{
    if (parent2[v] == -1)
        return v;
    int vl = getroot2(parent2[v]);
    parent2[v] = vl;
    return vl;
}

int union_snm1(int u, int v)
{
    if (rank1[u] < rank1[v])
        parent1[u] = v;
    else if (rank1[u] > rank1[v])
        parent1[v] = u;
    else
    {
        parent1[u] = v;
        rank1[v]++;
    }
}

int union_snm2(int u, int v)
{
    if (rank2[u] < rank2[v])
        parent2[u] = v;
    else if (rank2[u] > rank2[v])
        parent2[v] = u;
    else
    {
        parent2[u] = v;
        rank2[v]++;
    }
}
