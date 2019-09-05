#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const int MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const int N = 100001;
const int M = 12001;
typedef int uni;
int dpx[1048578], dpx2[1048578], dpy[1048578], dpy2[1048578], vx[1048578], vy[1048578], n;
uni bitnull(uni v, uni ind)
{
    return v & (~(1 << ind));
}
uni non(uni v)
{
    uni i = 0, ans = 0, j = v, t = 1;
    for (i = 0; i < n; i++)
    {
        if (!(j % 2))
            ans += t;
        t *= 2;
        j /= 2;
    }
    return ans;
}

int fx(int v);
int fy(int v);
int main()
{
    freopen("tickets.in", "r", stdin);
    freopen("tickets.out", "w", stdout);
    int i, mx = -1, val1 = 0, val2 = 0, ind1 = 0, ind2 = 0;
    cin >> n;
    for (i = 0; i < (1 << n); i++)
    {
        scanf("%d%d", &vx[i], &vy[i]);
        dpx[i] = -1;
        dpy[i] = -1;
    }

    for (i = 0; i < (1 << n); i++)
    {
        val1 = vx[i] + fy(non(uni(i)));
        val2 = vy[i] + fx(non(uni(i)));
        if (val1 > mx)
        {
            mx = val1;
            ind1 = i;
            ind2 = dpy2[non(uni(i))];
        }

        if (val2 > mx)
        {
            mx = val2;
            ind1 = dpx2[non(uni(i))];
            ind2 = i;
        }
    }

    cout << ind1 << ' ' << ind2 << endl;
    return 0;
}

int fx(int v)
{
    if (dpx[v] != -1)
        return dpx[v];
    int j = v, i = 0, mx = vx[v], ind = v, val, val2;
    while (j > 0)
    {
        if (j % 2)
        {
            val = bitnull(uni(v), uni(i));
            val2 = fx(val);
            if (val2 > mx)
            {
                mx = val2;
                ind = dpx2[val];
            }
        }
        j /= 2;
        i++;
    }
    dpx[v] = mx;
    dpx2[v] = ind;
    return mx;
}

int fy(int v)
{
    if (dpy[v] != -1)
        return dpy[v];
    int j = v, i = 0, mx = vy[v], ind = v, val, val2;
    while (j > 0)
    {
        if (j % 2)
        {
            val = bitnull(uni(v), uni(i));
            val2 = fy(val);
            if (val2 > mx)
            {
                mx = val2;
                ind = dpy2[val];
            }
        }
        j /= 2;
        i++;
    }
    dpy[v] = mx;
    dpy2[v] = ind;
    return mx;
}
