#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct xyz
{
    ll x, y, z;
};

bool comp(xyz a, xyz b);
xyz a[100010];
ll mx[100010], pmx[100010], imx[100010], ipmx[100010], an1[100010], an2[100010];
int main()
{
    ll n, i, vl, sm, h = 0, h1, h2, c1, c2, cnt1 = 0, cnt2 = 0, l = 0, r = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &a[i].x, &a[i].y);
        a[i].z = i + 1;
    }

    sort(a, a + n, comp);
    for (i = 0; i < n; i++)
    {
        if ((i == 0) || (a[i - 1].x != a[i].x))
        {
            vl = 0;
            sm = a[i].y;
        }
        else
        {
            vl++;
            sm += a[i].y;
        }

        if (sm > mx[vl])
        {
            pmx[vl] = mx[vl];
            ipmx[vl] = imx[vl];
            mx[vl] = sm;
            imx[vl] = a[i].x;
        }
        else if (sm > pmx[vl])
        {
            pmx[vl] = sm;
            ipmx[vl] = a[i].x;
        }
    }

    for (i = 0; i < n; i++)
    {
        if ((imx[i] > 0) && (ipmx[i] > 0) && (mx[i] + pmx[i] > h))
        {
            h = mx[i] + pmx[i];
            h1 = i;
            h2 = i;
            c1 = imx[i];
            c2 = ipmx[i];
        }

        if ((i - 1 >= 0) && (imx[i] > 0) && (imx[i - 1] > 0) && (imx[i] != imx[i - 1]) && (mx[i] + mx[i - 1] > h))
        {
            h = mx[i] + mx[i - 1];
            h1 = i;
            h2 = i - 1;
            c1 = imx[i];
            c2 = imx[i - 1];
        }

        if ((i - 1 >= 0) && (imx[i] > 0) && (ipmx[i - 1] > 0) && (imx[i] != ipmx[i - 1]) && (mx[i] + pmx[i - 1] > h))
        {
            h = mx[i] + pmx[i - 1];
            h1 = i;
            h2 = i - 1;
            c1 = imx[i];
            c2 = ipmx[i - 1];
        }
    }

    for (i = 0; i < n; i++)
    {
        if ((i == 0) || (a[i - 1].x != a[i].x))
            vl = 0;
        else
            vl++;

        if ((a[i].x == c1) && (vl <= h1))
        {
            cnt1++;
            an1[cnt1 - 1] = a[i].z;
        }

        if ((a[i].x == c2) && (vl <= h2))
        {
            cnt2++;
            an2[cnt2 - 1] = a[i].z;
        }
    }

    cout << h << endl;
    cout << cnt1 + cnt2 << endl;
    for (i = 0; i < cnt1 + cnt2; i++)
    {
        if (i % 2)
        {
            r++;
            printf("%I64d ", an2[r - 1]);
        }
        else
        {
            l++;
            printf("%I64d ", an1[l - 1]);
        }
    }
    return 0;
}

bool comp(xyz a, xyz b)
{
    return ((a.x < b.x) || ((a.x == b.x) && (a.y > b.y)) || ((a.x == b.x) && (a.y == b.y) && (a.z < b.z)));
}
