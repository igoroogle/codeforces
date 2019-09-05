#include <bits/stdc++.h>
using namespace std;
const int DL = 1000100;
const int INF = 2000000100;
int a[100010], izm[DL], raz[100010], up[100010], down[100010], n, m, k, t[400010], add[400010];
set<int> f[DL], s[DL];
void build(int l, int r, int v);
void push(int v);
void update(int l, int r, int v, int tl, int tr, int val);
int get(int l, int r, int v, int tl, int tr);
void addv(int ind, int x);
int main()
{
    //freopen("different.in", "r", stdin);
    //freopen("different.out", "w", stdout);
    int i, ans = 0, type, x, y;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        f[a[i]].insert(i);
        s[a[i]].insert(-i);
        if (i - k > 0)
        {
            if (izm[a[i - k]] == 1)
                ans--;
            izm[a[i - k]]--;
        }
        if (izm[a[i]] == 0)
            ans++;
        izm[a[i]]++;
        if (i - k >= 0)
            raz[i - k + 1] = ans;
    }

    for (i = 0; i < DL; i++)
        izm[i] = -INF;

    for (i = 1; i <= n; i++)
    {
        down[i] = izm[a[i]];
        izm[a[i]] = i;
    }

    for (i = 0; i < DL; i++)
        izm[i] = INF;

    for (i = n; i >= 1; i--)
    {
        up[i] = izm[a[i]];
        izm[a[i]] = i;
    }

    for (i = 0; i < DL; i++)
    {
        f[i].insert(INF);
        s[i].insert(INF);
    }

    build(1, n, 1);

    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1)
            addv(x, y);
        else
            printf("%d\n", get(1, n, 1, x, y - k + 1));
    }
    return 0;
}


void build(int l, int r, int v)
{
    int m;
    if (l == r)
    {
        t[v] = raz[l];
        add[v] = 0;
        return;
    }

    m = (l + r) / 2;
    build(l, m, v + v);
    build(m + 1, r, v + v + 1);
    t[v] = max(t[v + v], t[v + v + 1]);
    add[v] = 0;
}

void push(int v)
{
    add[v + v] += add[v];
    add[v + v + 1] += add[v];
    add[v] = 0;
}

void update(int l, int r, int v, int tl, int tr, int val)
{
    int m;
    if (tl > tr)
        return;

    if ((tl == l) && (tr == r))
    {
        add[v] += val;
        return;
    }
    m = (l + r) / 2;
    push(v);
    update(l, m, v + v, tl, min(tr, m), val);
    update(m + 1, r, v + v + 1, max(tl, m + 1), tr, val);
    t[v] = max(t[v + v] + add[v + v], t[v + v + 1] + add[v + v + 1]);
    add[v] = 0;
}

int get(int l, int r, int v, int tl, int tr)
{
    int m;
    if (tl > tr)
        return -INF;
    if ((tl == l) && (tr == r))
        return t[v] + add[v];
     m = (l + r) / 2;
     return max(get(l, m, v + v, tl, min(tr, m)), get(m + 1, r, v + v + 1, max(tl, m + 1), tr)) + add[v];
}

void addv(int ind, int x)
{
    int l, r, dd = down[ind], uu = up[ind];
    if (a[ind] == x)
        return;
    f[a[ind]].erase(ind);
    s[a[ind]].erase(-ind);
    a[ind] = x;
    l = max(ind - k + 1, 1);
    r = min(ind + k - 1, n - k + 1);
    //cout << l << ' ' << r << " lr0\n";
    //cout << dd << ' ' << uu << endl;
    if (dd != -INF)
    {
        l = max(l, dd + 1);
        up[dd] = uu;
    }

    if (uu != INF)
    {
        r = min(r, uu - k);
        down[uu] = dd;
    }
    //cout << l << ' ' << r << " lrf\n";
    if (l <= r)
        update(1, n, 1, l, r, -1);

    uu = *f[x].upper_bound(ind);
    f[x].insert(ind);
    dd = -(*s[x].upper_bound(-ind));
    s[x].insert(-ind);
    if (dd != -INF)
        up[dd] = ind;
    if (uu != INF)
        down[uu] = ind;
    l = max(ind - k + 1, 1);
    r = min(ind + k - 1, n - k + 1);
    //cout << l << ' ' << r << " lr0\n";
    //cout << dd << ' ' << uu << endl;
    if (dd != -INF)
        l = max(l, dd + 1);

    if (uu != INF)
        r = min(r, uu - k);
    //cout << l << ' ' << r << " lrs\n";
    if (l <= r)
        update(1, n, 1, l, r, 1);
}

/*
5 3 3
1 2 1 3 3
2 1 3
1 3 3
2 1 5
*/

/*
6 6 3
2 3 1 1 1 9
2 1 3
2 3 5
1 3 3
2 1 5
1 2 1
2 1 6
*/
