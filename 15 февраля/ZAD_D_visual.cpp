#include <iostream>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
const ll INF = 2E18;
const ll DL = 317;
const ll DL2 = 100010;
ll block[DL2], bl[DL], br[DL], next[DL2], minv[DL], a[DL2], d[DL2], ans[DL2], nex[DL2];
pair< pair<ll, ll>, pair<ll, ll> > ar[DL2];
int main()
{
    freopen("hotels.in", "r", stdin);
    freopen("hotels.out", "w", stdout);
    ll n, t, i, j, p, l, r, k, vl, vl2, vl3, mn, u;

    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d%I64d", &a[i], &d[i]);

    cin >> t;
    for (i = 0; i < t; i++)
    {
        scanf("%I64d%I64d%I64d", &l, &r, &k);
        l--;
        r--;
        k--;
        ar[i] = mp(mp(k, i), mp(l, r));
    }

    sort(ar, ar + t);

    for (i = 0; i < n; i++)
    {
        if (i % DL == 0)
            bl[i / DL] = i;
        br[i / DL] = i;
        block[i] = i / DL;
    }

    for (i = 0; i < n; i++)
    {
        nex[i] = -1;
        k = -1;
        for (j = bl[block[i]]; j <= br[block[i]]; j++)
            if ((d[i] > d[j]) && (a[i] <= a[j]))
            {
                vl = (a[j] - a[i]) / (d[i] - d[j]) + 1;
                if (k == -1)
                    k = vl;
                else
                    k = min(k, vl);
            }

        if (k != -1)
        {
            vl = -1;
            for (j = bl[block[i]]; j <= br[block[i]]; j++)
            if ((d[i] > d[j]) && (a[i] <= a[j]))
            {
                vl2 = a[j] + d[j] * k;
                if (vl == -1)
                    vl = j;
                else
                {
                    vl3 = a[vl] + d[vl] * k;
                    if (vl3 > vl2)
                        vl = j;
                }
            }
            nex[i] = vl;
        }
    }

    for (i = block[0]; i <= block[n - 1]; i++)
    {
        mn = bl[i];
        for (j = bl[i] + 1; j <= br[i]; j++)
            if (a[j] < a[mn])
                mn = j;
        minv[i] = mn;
    }

    //cout << bl[0] << ' ' << br[0] << ' ' << bl[1] << ' ' << br[1] << endl;

    for (p = 0; p < t; p++)
    {
        mn = INF;
        k = ar[p].x.x;
        l = ar[p].y.x;
        r = ar[p].y.y;
        i = l;
        for(;;)
        {
            mn = min(mn, a[i] + d[i] * k);
            if ((i + 1 > r) || (block[i + 1] != block[i]))
                break;
            i++;
        }

        i = r;
        for(;;)
        {
            mn = min(mn, a[i] + d[i] * k);
            if ((i - 1 < l) || (block[i - 1] != block[i]))
                break;
            i--;
        }

        for (i = block[l] + 1; i < block[r]; i++)
        {
            while (nex[minv[i]] != -1)
            {
                j = minv[i];
                u = nex[j];
                if (a[j] + d[j] * k > a[u] + d[u] * k)
                    minv[i] = u;
                else
                    break;
            }
            j = minv[i];
            mn = min(mn, a[j] + d[j] * k);
        }
        ans[ar[p].x.y] = mn;
    }

    for (i = 0; i < t; i++)
        printf("%I64d\n", ans[i]);
    return 0;
}


/*
2
1 4
3 1
2
1 1 3
1 2 3
*/
