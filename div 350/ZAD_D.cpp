#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
ll a[100010], b[100010], n, k;
bool prov(ll x);
int main()
{
    ll m, i, l, r;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);


    for (i = 0; i < n; i++)
        scanf("%I64d", &b[i]);

    l = 0;
    r = ll(2000000001);
    while (l < r)
    {
        m = (l + r) >> ll(1);
        if (prov(m))
            l = m + 1;
        else
            r = m;
    }

    cout << ll(l - 1) << endl;
    return 0;
}

bool prov(ll x)
{
    ll k1 = k, i;
    for (i = 0; i < n; i++)
    {
        if (a[i] * x <= b[i])
            continue;
        k1 -= (a[i] * x - b[i]);
        if (k1 < 0)
            return 0;
    }
    return 1;
}
