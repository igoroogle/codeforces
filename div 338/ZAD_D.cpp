#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll a[200010], b[200010];
ll binst(ll x, ll n);
int main()
{
    ll n, m, i, j, ans = 1, stp, newans, newkol, val, kol = 1, vt = 0, rt;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    m = 1;
    b[0] = 1;

    for (i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            a[m++] = a[i];
            b[m - 1] = 1;
        }
        else
            b[m - 1]++;
    }

    for (i = 0; i < n; i++)
    {
        stp = 1;
        newans = ans;
        newkol = kol;
        rt = 0;
        for (j = 0; j < b[i]; j++)
        {
            stp = (stp * a[i]) % MOD;
            val = binst(stp, kol);
            if (vt > 0)
                val = (binst(binst(stp, MOD), vt) * val) % MOD;
            val = (val * ans) % MOD;
            newans = (val * newans) % MOD;
            if (newkol + kol > MOD)
            {
                newkol = newkol + kol - MOD;
                rt++;
            }
            else
                newkol = newkol + kol;
        }
        ans = newans;
        kol = newkol;
        vt += rt;
    }

    cout << ans << endl;
    return 0;
}

ll binst(ll x, ll n)
{
    if (n == 0)
        return ll(1);
    if (n == 1)
        return x;
    ll ans = binst(x, n / 2);
    ans = (ans * ans) % MOD;
    if (n % 2)
        ans = (ans * x) % MOD;
    return ans;
}
