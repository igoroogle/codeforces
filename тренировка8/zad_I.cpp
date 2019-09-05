#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll LEN = 500500, MOD = 1000000007;

struct tree
{
    ll n, t[LEN];

    tree(ll n)
    {
        this->n = n;
        for (int i = 0; i < 5 * n; i++)
            t[i] = 0;
    }

    void update(int v, int tl, int tr, int p, ll x);
    ll get(int v, int tl, int tr, int l, int r);
};

void tree::update(int v, int tl, int tr ,int p, ll x)
{
    if (tl == tr)
    {
        t[p] += x;
        if (t[p] >= MOD)
            t[p] -= MOD;
        return;
    }

    int tm = (tl + tr) / 2;

    if (p <= tm)
        update(v * 2, tl, tm, p, x);
    else
        update(v * 2 + 1, tm + 1, tr, p, x);

    t[v] = t[v * 2] + t[v * 2 + 1];
    if (t[v] >= MOD)
        t[v] -= MOD;
}

ll tree::get(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[v];

    int tm = (tl + tr) / 2;
    ll res = get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    if (res >= MOD)
        res -= MOD;

    return res;
}

int n;
tree tr(100100);

int main()
{
    //freopen("frac.in", "r", stdin);
    //freopen("frac.out", "w", stdout);



    return 0;
}
