#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ans[100010], st[100010];
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    ll x, i, n = 0, pwl, pwt, kol = 0;
    ld pw;
    cin >> x;
    for (i = 60; i >= 2; i--)
    {
        pw = pow(ld(x), ld(1.0 / ld(i)));
        pwl = ll(pw);
        pwt = round(pow(ld(pwl), ld(i)));
        if (pwt == x)
        {
            ans[kol] = pwl;
            st[kol++] = i;
        }

        else
        {
            pwl = ll(pw) + 1;
            pwt = round(pow(ld(pwl), ld(i)));
            if (pwt == x)
            {
                ans[kol] = pwl;
                st[kol++] = i;
            }

            if (pwt == x)
            {
                ans[kol] = pwl;
                st[kol++] = i;
            }
        }
    }

    cout << kol << endl;
    for (i = 0; i < kol; i++)
        printf("%I64d %I64d\n", ans[i], st[i]);
}
