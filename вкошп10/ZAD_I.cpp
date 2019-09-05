#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
struct tree
{
    tree *l, *r;
    ll t;
    tree()
    {
        l = NULL;
        r = NULL;
        t = 0;
    }
};

tree *vl[100010];
ll a[100010], t[100010];
void build(tree *a, ll l, ll r);
void update(tree *a, ll l, ll r, ll ind, ll x);
ll get(tree *a, ll l, ll r, ll k);
int main()
{

    freopen("rollback.in", "r", stdin);
    freopen("rollback.out", "w", stdout);
    ll n, m, q, p, i, x, y, l, k;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);

    vl[n + 1] = new tree();
    build(vl[n + 1], 1, n);
    for (i = n; i > 0; i--)
    {
        vl[i] = new tree();
        *vl[i] = *vl[i + 1];
        if (t[a[i]] != 0)
            update(vl[i], 1, n, t[a[i]], ll(0));
        update(vl[i], 1, n, i, ll(1));
        t[a[i]] = i;
    }

    cin >> q;
    p = 0;
    while(q--)
    {
        scanf("%I64d%I64d", &x, &y);
        l = ((x + p) % n) + 1;
        k = ((y + p) % m) + 1;
        p = get(vl[l], 1, n, k);
        printf("%I64d\n", p);
    }

    return 0;
}

void build(tree *a, ll l, ll r)
{
    if (a->l == NULL)
        a->l = new tree();

    if (a->r == NULL)
        a->r = new tree();
    if (l == r)
        return;

    ll m = (l + r) >> ll(1);
    build(a->l, l, m);
    build(a->r, m + 1, r);
}

void update(tree *a, ll l, ll r, ll ind, ll x)
{

    if (l == r)
    {
        a->t = x;
        return;
    }

    ll m = (l + r) >> ll(1);
    if (ind <= m)
    {
        tree *cp = new tree();
        *cp = *a->l;
        a->l = cp;
        update(a->l, l, m, ind, x);
    }
    else
    {
        tree *cp = new tree();
        *cp = *a->r;
        a->r = cp;
        update(a->r, m + 1, r, ind, x);
    }
    a->t = a->l->t + a->r->t;
}

ll get(tree *a, ll l, ll r, ll k)
{
    if (a->t < k)
        return ll(0);

    if (l == r)
        return l;
    ll m = (l + r) >> ll(1);
    if (a->l->t >= k)
        return get(a->l, l, m, k);
    else
        return get(a->r, m + 1, r, k - a->l->t);
}
