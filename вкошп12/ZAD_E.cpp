#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "jediacademy"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef unsigned int unt;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

vector<int> d[100010], t[2];
int typ[100010], kl[100010], kl2[100010];
int main()
{
    FREOPEN;
    int n, i, j, x, y, k, nf = 0, rt;
    ll ans, a, b, kk, mn;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &typ[i]);
        scanf("%d", &k);

        for (j = 0; j < k; j++)
        {
            scanf("%d", &x);
            x--;
            d[x].pb(i);
        }

        kl[i] = k;
        kl2[i] = k;
    }

    cin >> a >> b;
    ans = 0;

    for (i = 0; i < n; i++)
        if (kl[i] == 0)
            t[typ[i] - 1].pb(i);


    while (nf < n)
    {
        kk = 0;
        if (nf < n)
            ans += a;
        while (t[0].size() > 0)
        {
            kk++;
            rt = t[0][t[0].size() - 1];
            t[0].pop_back();
            for (i = 0; i < d[rt].size(); i++)
            {
                kl[d[rt][i]]--;
                if (kl[d[rt][i]] == 0)
                    t[typ[d[rt][i]] - 1].pb(d[rt][i]);
            }
        }

        ans += kk * b;
        nf += kk;
        kk = 0;
        if (nf < n)
            ans += a;
        while (t[1].size() > 0)
        {
            kk++;
            rt = t[1][t[1].size() - 1];
            t[1].pop_back();
            for (i = 0; i < d[rt].size(); i++)
            {
                kl[d[rt][i]]--;
                if (kl[d[rt][i]] == 0)
                    t[typ[d[rt][i]] - 1].pb(d[rt][i]);
            }
        }
        ans += kk * b;
        nf += kk;
    }
    mn = ans;
    ans = 0;
    nf = 0;
    for (i = 0; i < n; i++)
        {
            kl[i] = kl2[i];
            if (kl[i] == 0)
                t[typ[i] - 1].pb(i);
        }

    while (nf < n)
    {
        kk = 0;
        if (nf < n)
            ans += a;
        while (t[1].size() > 0)
        {
            kk++;
            rt = t[1][t[1].size() - 1];
            t[1].pop_back();
            for (i = 0; i < d[rt].size(); i++)
            {
                kl[d[rt][i]]--;
                if (kl[d[rt][i]] == 0)
                    t[typ[d[rt][i]] - 1].pb(d[rt][i]);
            }
        }

        ans += kk * b;
        nf += kk;
        kk = 0;
        if (nf < n)
            ans += a;

        while (t[0].size() > 0)
        {
            kk++;
            rt = t[0][t[0].size() - 1];
            t[0].pop_back();
            for (i = 0; i < d[rt].size(); i++)
            {
                kl[d[rt][i]]--;
                if (kl[d[rt][i]] == 0)
                    t[typ[d[rt][i]] - 1].pb(d[rt][i]);
            }
        }
        ans += kk * b;
        nf += kk;
    }

    mn = min(ans, mn);
    cout << mn << endl;
    return 0;
}


/*





*/


