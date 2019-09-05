#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1E18;
ll a[110][110], b[110][110], cl[110], cr[110];
ll getsum(ll i,ll l, ll r);
int main()
{
    ll i, j, k, n, kl = 0, mn, ind, s1 = 0, s2 = 0, vl, l, r, ln;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i][0]);
        for (j = 1; j <= a[i][0]; j++)
        {
            scanf("%d", &a[i][j]);
            b[i][j] = b[i][j - 1] + a[i][j];
            cl[i] = 1;
            cr[i] = a[i][0];
            kl++;
        }
    }

    for (k = 0; k < kl; k++)
    {
        mn = -INF;
        ind = -1;
        for (i = 0; i < n; i++)
            if (cl[i] <= cr[i])
            {
                if (k % 2)
                {
                    ln = cr[i] - cl[i] + 1;
                    l = cr[i] - ((ln - 1) / 2);
                    r = cr[i];
                    vl = getsum(i, l, r) - getsum(i, cl[i], l - 1);
                    if (vl > mn)
                    {
                        mn = vl;
                        ind = i;
                    }
                }
                else
                {
                    ln = cr[i] - cl[i] + 1;
                    l = cl[i];
                    r = (ln - 1) / 2 + cl[i];
                    vl = getsum(i, l, r) - getsum(i, r + 1, cr[i]);
                    if (vl > mn)
                    {
                        mn = vl;
                        ind = i;
                    }
                }
            }

        if (k % 2)
        {
            s2 += a[ind][cr[ind]];
            cr[ind]--;
        }
        else
        {
            s1 += a[ind][cl[ind]];
            cl[ind]++;
        }
    }

    cout << s1 << ' ' << s2 << endl;
    return 0;
}

ll getsum(ll i,ll l, ll r)
{
    if (l > r)
        return 0;
    return b[i][r] - b[i][l - 1];
}
