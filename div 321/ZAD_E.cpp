#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ll P = 237;
const ll DL = 100010;
const ll DL2 = 262146;
ll t[DL2], add[DL2], pw[DL], val[10][DL], n, m, k;
string s;
void build(ll l, ll r, ll v);
void update(ll l, ll r, ll v, ll tl, ll tr, ll x);
void push(ll v);
ll get(ll l, ll r, ll v, ll tl, ll tr);
bool comp_hash(ll l1, ll r1, ll l2, ll r2);
bool podl(ll l, ll r, ll d);
int main()
{
    ll i, j, typ, l, r, d;
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

    cin >> s;
    build(1, n, 1);
    for (i = 0; i < m + k; i++)
    {
        scanf("%I64d%I64d%I64d%I64d", &typ, &l, &r, &d);
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

void build(ll l, ll r, ll v)
{
    ll m;
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

void push(ll v)
{
    if (add[v] == -1)
        return;
    add[v + v] = add[v];
    add[v + v + 1] = add[v];
}

void update(ll l, ll r, ll v, ll tl, ll tr, ll x)
{
    ll m, ans1, ans2;
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

ll get(ll l, ll r, ll v, ll tl, ll tr)
{
    ll m, ans1, ans2, l1, r1, l2, r2;
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

bool comp_hash(ll l1, ll r1, ll l2, ll r2)
{
    if ((r1 < l1) || (r2 < l2) || (r1 - l1 != r2 - l2))
        return 0;
    return get(1, n, 1, l1, r1) == get(1, n, 1, l2, r2);
}

bool podl(ll l, ll r, ll d)
{
    ll vl = r - l + 1;
    if (vl <= d)
        return 1;
    ll ost = vl % d;
    if (ost)
    {
        if (!comp_hash(r - d - ost + 1, r - d, r - ost + 1, r))
            return 0;
        return podl(l, r - ost, d);
    }

    ll kol = vl / d;
    if (kol % 2)
    {
        if (!comp_hash(r - d - d + 1, r - d, r - d + 1, r))
            return 0;
        return podl(l, r - d, d);
    }

    ll m = kol / 2 * d;
    if (!comp_hash(l, l + m - 1, l + m, r))
        return 0;
    return podl(l, l + m - 1, d);
}
