#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 100010;
vector<int> a[DL], b[DL];
int kor = 1, type[DL], h[DL], t[4*DL], start[DL], dp[DL], id[DL], sum = 0, sum2, sum3, n;
void dfs(int v, int p);
void update(int l, int r, int v, int ind, int x);
int get(int l, int r, int v, int tl, int tr);
int answer(int x, int y);
int main()
{
    int m, i, typ, x, y;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        b[x].push_back(i + 1);
        a[y].push_back(x);
        b[y].push_back(i + 1);
        if (a[x].size() > a[kor].size())
            kor = x;
        if (a[y].size() > a[kor].size())
            kor = y;
    }
    h[kor] = sum++;
    type[kor] = 0;
    start[0] = kor;
    sum2 = 1;
    for (i = 0; i < a[kor].size(); i++)
    {
        start[sum2] = sum;
        sum3 = 1;
        dfs(a[kor][i], kor);
        id[b[kor][i]] = a[kor][i];
        sum2++;
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &typ, &x);
        if (typ == 1)
            update(1, n, 1, h[id[x]], 0);
        else if (typ == 2)
            update(1, n, 1, h[id[x]], 1);
        else
        {
            scanf("%d", &y);
            printf("%d\n", answer(x, y));
        }
    }
    return  0;
}

void dfs(int v, int p)
{
    h[v] = sum++;
    dp[v] = sum3++;
    type[v] = sum2;
    int i;
    for (i = 0; i < a[v].size(); i++)
        if (a[v][i] != p)
            {
                dfs(a[v][i], v);
                id[b[v][i]] = a[v][i];
            }
}

void update(int l, int r, int v, int ind, int x)
{
    int m;
    if (l == r)
    {
        t[v] = x;
        return;
    }

    m = (l + r) / 2;
    if (ind <= m)
        update(l, m, v + v, ind, x);
    else
        update(m + 1, r, v + v + 1, ind, x);
    t[v] = t[v + v] + t[v + v + 1];
}

int get(int l, int r, int v, int tl, int tr)
{
    int m;
    if (tl > tr)
        return 0;
    if ((l == tl) && (r == tr))
        return t[v];
    m = (l + r) / 2;
    return get(l, m, v + v, tl, min(tr, m)) + get(m + 1, r, v + v + 1, max(tl, m + 1), tr);
}

int answer(int x, int y)
{
    int sm;
    if (x == y)
        return 0;
    if (h[x] > h[y])
        swap(x, y);

    if (type[x] == type[y])
    {
        sm = get(1, n, 1, h[x] + 1, h[y]);
        if (sm > 0)
            return -1;
        return h[y] - h[x];
    }

    if (x == kor)
    {
        sm = get(1, n, 1, start[type[y]], h[y]);
        if (sm > 0)
            return -1;
        return dp[y];
    }
    sm = get(1, n, 1, start[type[x]], h[x]) + get(1, n, 1, start[type[y]], h[y]);
    if (sm > 0)
        return -1;
    return dp[x] + dp[y];
}
