#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1E-11;
int a[200010], n;
double sum[200010], smx[200010];
double rec(double x);
int main()
{
    int  i;
    double l, r, m1, m2;
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    l = -10010.0;
    r = 10010.0;
    while (r - l > EPS)
    {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        if (rec(m1) > rec(m2))
            l = m1;
        else
            r = m2;
    }
    printf("%.25lf\n", (rec(l) + rec(r)) / 2.0);//uffg
    return 0;
}
double rec(double x)
{
    int ind1, ind2, i;
    double val, mx = 0.0;
    ind1 = 0;
    ind2 = 0;
    sum[0] = 0.0;
    smx[0] = 0.0;
    for (i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + double(a[i]) - x;
        if (double(a[i]) - x > EPS)
        {
            val = sum[i] - sum[ind1] + smx[ind1];
            smx[i] = max(double(a[i]) - x, val);
            ind1 = i;
        }

        else
        {
            val = sum[i] - sum[ind2] + smx[ind2];
            smx[i] = min(double(a[i]) - x, val);
            ind2 = i;
        }
        mx = max(abs(smx[i]), mx);
    }
    return mx;
}
