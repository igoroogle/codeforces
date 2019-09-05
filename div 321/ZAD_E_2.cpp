#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ll P = 237;
const ll DL = 100010;
const ll DL2 = 262146;
ll t[DL2], add[DL2], pw[DL], val[10][DL];
char s[DL];
int n, m, k;
void build(int l, int r, int v);
void update(int l, int r, int v, int tl, int tr, int x);
void push(int v);
ll get(int l, int r, int v, int tl, int tr);
bool comp_hash(int l1, int r1, int l2, int r2);
bool podl(int l, int r, int d);
int main()
{
    int i, j, typ, l, r, d;
    cin >> n >> m >> k;
    pw[0] = 1;
    for (i = 1; i < DL; i++)
        pw[i] = (pw[i - 1] * P) % MOD;
    for (i = 0; i < 10; i++)
    {
        val[i][0] = i + 1;
        for (j = 1; j < DL; j++)
            val[i][j] = (val[i][j - 1] * P + i + 1) % MOD;
    }

    scanf("\n%s", &s);
    build(1, n, 1);
    for (i = 0; i < m + k; i++)
    {
        scanf("%d%d%d%d", &typ, &l, &r, &d);
        if (typ == 1)
            update(1, n, 1, l, r, d);
        else
        {
            if (podl(l, r, d))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}

void build(int l, int r, int v)
{
    int m;
    if (l == r)
    {
        t[v] = ll(s[l - 1] - '0' + 1);
        add[v] = -1;
        return;
    }
    m = (l + r) / 2;
    build(l, m, v + v);
    build(m + 1, r, v + v + 1);
    t[v] = (t[v + v] * pw[r - m]) % MOD;
    t[v] = (t[v] + t[v + v + 1]) % MOD;
    add[v] = -1;
}

void push(int v)
{
    if (add[v] == -1)
        return;
    add[v + v] = add[v];
    add[v + v + 1] = add[v];
}

void update(int l, int r, int v, int tl, int tr, int x)
{
    int m;
    ll ans1, ans2;
    if (tl > tr)
        return;
    if ((tl == l) && (tr == r))
    {
        add[v] = x;
        return;
    }
    m = (l + r) / 2;
    push(v);
    update(l, m, v + v, tl, min(m, tr), x);
    update(m + 1, r, v + v + 1, max(tl, m + 1), tr, x);
    if (add[v + v] == -1)
        ans1 = t[v + v];
    else
        ans1 = val[add[v + v]][m - l];
    if (add[v + v + 1] == -1)
        ans2 = t[v + v + 1];
    else
        ans2 = val[add[v + v + 1]][r - m - 1];
    ans1 = (ans1 * pw[r - m]) % MOD;
    t[v] = (ans1 + ans2) % MOD;
    add[v] = -1;
}

ll get(int l, int r, int v, int tl, int tr)
{
    int m;
    ll ans1, ans2;
    int l1, r1, l2, r2;
    if (tl > tr)
        return 0;
    if (add[v] != -1)
        return val[add[v]][tr - tl];
    if ((tl == l) && (tr == r))
        return t[v];
    m = (l + r) / 2;
    l1 = tl;
    r1 = min(tr, m);
    l2 = max(m + 1, tl);
    r2 = tr;
    push(v);
    ans1 = get(l, m, v + v, l1, r1);
    ans2 = get(m + 1, r, v + v + 1, l2, r2);
    if (l2 <= r2)
        ans1 = (ans1 * pw[r2 - l2 + 1]) % MOD;
    return (ans1 + ans2) % MOD;
}

bool comp_hash(int l1, int r1, int l2, int r2)
{
    if ((r1 < l1) || (r2 < l2) || (r1 - l1 != r2 - l2))
        return 0;
    return get(1, n, 1, l1, r1) == get(1, n, 1, l2, r2);
}

bool podl(int l, int r, int d)
{
    int vl = r - l + 1;
    if (vl <= d)
        return 1;
    int ost = vl % d;
    if (ost)
    {
        if (!comp_hash(r - d - ost + 1, r - d, r - ost + 1, r))
            return 0;
        return podl(l, r - ost, d);
    }

    int kol = vl / d;
    if (kol % 2)
    {
        if (!comp_hash(r - d - d + 1, r - d, r - d + 1, r))
            return 0;
        return podl(l, r - d, d);
    }

    int m = kol / 2 * d;
    if (!comp_hash(l, l + m - 1, l + m, r))
        return 0;
    return podl(l, l + m - 1, d);
}
