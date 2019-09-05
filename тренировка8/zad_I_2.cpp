#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll LEN = 500500, MOD = 1000000007;
const int INF = 2000000010;
const int MOD = 1000000007;
struct node
{
    int y, val, kl, val;
    pair<int, int> x, val, mx;
    node *l, *r;
    node(pair<int, int> x)
    {
        this->x = x;
        y = (rand() << 15) ^ rand();
        val = 0;
        mx = 0;
        kl = 1;
        l = NULL;
        r = NULL;
    }
};

int cntmx(node* v)
{
    if (v == NULL)
        return -INF;
    return v->mx;
}

int cntkl(node* v)
{
    if (v == NULL)
        return 0;
    return v->kl;
}

void update(node* v)
{
    if (v == NULL)
        return;
    v->mx = v->val;
    v->kl = 1;
    if (v->mx > cntmx(v->l))
    {
        v->mx = cntmx(v->l);
        v->kl = cntkl(v->l);
    }
    else if (v->mx == cntmx(v->l))
        v->kl = (cntkl(v->l) + v->kl) % MOD;

    if (v->mx > cntmx(v->r))
    {
        v->mx = cntmx(v->r);
        v->kl = cntkl(v->r);
    }

    else if (v->mx == cntmx(v->r))
        v->kl = (cntkl(v->r) + v->kl) % MOD;
}

pair<node*, node*> split(node* t, pair<int, int> x)
{
    pair<node*, node*> tt = make_pair((node*)NULL, (node*)NULL);
    if (t == NULL)
        return tt;

    if (t->x <= x)
    {
        pair<node*, node*> tt2 = split(t->r, x);
        tt.second = tt2.second;
        t->r = tt2.first;
        update(t);
        tt.first = t;
        return tt;
    }

    pair<node*, node*> tt2 = split(t->l, x);
    tt.first = tt2.first;
    t->l = tt2.second;
    update(t);
    tt.second = t;
    return tt;
}

node* merge(node* l, node* r)
{
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    if (l->y < r->y)
    {
        l->r = merge(t->r, r);
        update(l);
        return l;
    }
    r->l = merge(l, t->l);
    update(r);
    return r;
}

int count(node*& t, pair<int, int> x)
{
    pair<node*, node*> tt = split(t, x);
    pair<pair<int, int>, int> ans;
    ans.first = cntmx(tt.first);
    ans.second = cntkl(tt.first);
    t = merge(tt.first, tt.second);
    return ans;
}

node* add(pair<int, int> x, int val)
{
    pair<node*, node*> tt = split(t, x);
    node* nw = new node(x);
    nw->val = val;
    node* t = merge(tt.first, nw);
    node* t2 = merge(t, tt.second);
    return t2;
}

int main()
{
    //freopen("frac.in", "r", stdin);
    //freopen("frac.out", "w", stdout);
    int i, x, ans, anss = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            ans =
        }
    return 0;
}
