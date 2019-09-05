#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
struct bor
{
    bor *t[2];
    int cur;
    bor()
    {
        t[0] = NULL;
        t[1] = NULL;
        cur = 0;
    }
};


void add(int a[], int ind, int n, bor *b);
void del(int a[], int ind, int n, bor *b);
ll get_ans(int a[], int ind, int n, bor *b, ll st);
bor *b = new bor();
int a[33];
int main()
{
    ll ans = 0;
    int q, i, n;
    for (i = 0; i < 200010; i++)
        add(a, 0, 31, b);

    char c;
    cin >> q;
    while (q--)
    {
        scanf("\n%c%d", &c, &n);
        for (i = 0; i < 31; i++)
        {
            a[i] = (n & 1);
            n = (n >> 1);
        }
        reverse(a, a + 31);

        if (c == '+')
            add(a, 0, 31, b);
        else if (c == '-')
            del(a, 0, 31, b);
        else
            printf("%I64d\n", get_ans(a, 0, 31, b, (ll(1) << ll(30))));
    }

    return 0;
}

void add(int a[], int ind, int n, bor *b)
{

    b->cur++;
    if (ind >= n)
        return;
    if (b->t[a[ind]] == NULL)
        b->t[a[ind]] = new bor();
    add(a, ind + 1, n, b->t[a[ind]]);
}

void del(int a[], int ind, int n, bor *b)
{
    b->cur--;
    if (ind >= n)
        return;
    del(a, ind + 1, n, b->t[a[ind]]);
}

ll get_ans(int a[], int ind, int n, bor *b, ll st)
{
    if (b->cur == 0)
        return ll(0);

    if (ind >= n)
        return ll(0);

    if (((b->t[0] == NULL) ||  (b->t[0]->cur == 0)) && ((b->t[1] == NULL) || (b->t[1]->cur == 0)))
        return ll(0);

    ll an;

    if ((b->t[0] == NULL) || (b->t[0]->cur == 0))
    {
        if (a[ind] == 0)
            an = st;
        else
            an = 0;
        return (ll(get_ans(a, ind + 1, n, b->t[1], (st >> ll(1)))) + an);
    }

    if ((b->t[1] == NULL) || (b->t[1]->cur == 0))
    {
        if (a[ind] == 1)
            an = st;
        else
            an = 0;

        return (ll(get_ans(a, ind + 1, n, b->t[0], (st >> ll(1)))) + an);
    }

    an = st;
    if (a[ind] == 0)
        return (ll(get_ans(a, ind + 1, n, b->t[1], (st >> ll(1)))) + an);
    else
        return (ll(get_ans(a, ind + 1, n, b->t[0], (st >> ll(1)))) + an);
}
