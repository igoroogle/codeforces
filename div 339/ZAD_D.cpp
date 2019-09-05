#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010];
int main()
{
    ll n, a1, cf, cm, m, i, kmn = 1, kmx = 0, ind1, ind2;
    cin >> n >> a1 >> cf >> cm >> m;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    ind1 = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            break;
        kmn++;
        ind1 = i;
    }

    ind2
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] == a1)
            {
                kmx++;
                ind2 = i;
            }
    }

    while (m > 0)
    {
        if (kmn)
    }
    return 0;
}
