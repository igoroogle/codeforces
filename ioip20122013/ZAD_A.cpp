#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 62;
ll pw[DL];
ll get_ans(ll n, ll p);
int main()
{
    freopen("hat.in", "r", stdin);
    freopen("hat.out", "w", stdout);
    ll i, n, p, q;
    cin >> q;
    pw[0] = 1;
    for (i = 1; i < DL; i++)
        pw[i] = pw[i - 1] + pw[i - 1];
    while (q--)
    {
        scanf("%I64d%I64d", &n, &p);
        printf("%I64d\n", get_ans(n, p));
    }

    return 0;
}

ll get_ans(ll n, ll p)
{
    if (n == 1)
        return ll(0);
    ll l = 0, r = DL - 1, m;
    while (l < r)
    {
        m = (l + r) >> ll(1);
        if (pw[m] < n)
            l = m + ll(1);
        else
            r = m;
    }
    return (get_ans(n - pw[l - 1], p) + ll(1)) % p;
}
