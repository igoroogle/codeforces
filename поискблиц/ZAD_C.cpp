#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010];
int main()
{
    int n, k, i, l;
    ll s = 0, mn, mxval, vl;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    l = 0;
    sort(a, a + n);
    mn = a[0];
    mxval = 1;

    for (i = 1; i < n; i++)
    {
        vl = ll(a[i]) - ll(a[i - 1]);
        s += vl * ll(i - l);

        while (s > k)
        {
            s -= ll(a[i]) - ll(a[l]);
            l++;
        }

        if (i - l + 1 > mxval)
        {
            mxval = i - l + 1;
            mn = a[i];
        }
    }

    cout << mxval << ' ' << mn << endl;
    return 0;
}
