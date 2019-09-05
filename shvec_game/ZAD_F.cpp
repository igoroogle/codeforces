#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;

const ll MOD = 1000000009;

void add(ll x, ll y);
void del(ll x, ll y, ll m);
ll getmin();
ll getmax();

map< pair<ll, ll>, ll> t;
set< pair<ll, pair<ll, ll> > > mxv;
set< pair<ll, pair<ll, ll> > > mnv;
ll a[100010], b[100010], pw[100010], n;

int main()
{
    ll m, i, pp, ans = 0, val;
    cin >> m;
    n = m;
    for(i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &a[i], &b[i]);
        t[mp(a[i], b[i])] = i + 1;
    }

    for (i = 0; i < m; i++)
        add(a[i], b[i]);
    pw[0] = 1;
    for (i = 1; i < m; i++)
        pw[i] = (pw[i - 1] * m) % MOD;
    pp = m - 1;
    for (i = 0; i < m; i++)
    {
        if (i % 2)
            val = getmin();
        else
            val = getmax();
        val--;
        ans = (ans + val * pw[pp]) % MOD;
        pp--;
    }

    cout << ans << endl;
    return 0;
}

void add(ll x, ll y)
{
    ll val = t[mp(x, y)];
    if (val == 0)
        return;
    if (t[mp(x - 1, y + 1)])
    {
        if ((!t[mp(x - 1, y)]) && (!t[mp(x - 2, y)]))
        {
            mnv.erase(mp(val, mp(x, y)));
            mxv.erase(mp(-val, mp(x, y)));
            return;
        }
    }

    if (t[mp(x, y + 1)])
    {
        if ((!t[mp(x - 1, y)]) && (!t[mp(x + 1, y)]))
        {
            mnv.erase(mp(val, mp(x, y)));
            mxv.erase(mp(-val, mp(x, y)));
            return;
        }
    }

    if (t[mp(x + 1, y + 1)])
    {
        if ((!t[mp(x + 1, y)]) && (!t[mp(x + 2, y)]))
        {
            mnv.erase(mp(val, mp(x, y)));
            mxv.erase(mp(-val, mp(x, y)));
            return;
        }
    }


    mnv.insert(mp(val, mp(x, y)));
    mxv.insert(mp(-val, mp(x, y)));
}

void del(ll x, ll y, ll m)
{
    mnv.erase(mp(m, mp(x, y)));
    mxv.erase(mp(-m, mp(x, y)));
    t[mp(x, y)] = 0;
    for (int i = -2; i <= 2; i++)
        for (int j = -2; j <= 2; j++)
            add(x + i, y + j);
}

ll getmin()
{
    pair<ll, pair<ll, ll> > f = *mnv.begin();
    del(f.y.x, f.y.y, f.x);
    return f.x;
}

ll getmax()
{
    pair<ll, pair<ll, ll> > f = *mxv.begin();
    del(f.y.x, f.y.y, -f.x);
    return -f.x;
}
