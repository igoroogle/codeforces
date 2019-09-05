#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 300000;
const ll INF = 2E18;
ll dp[13][300010], pr[13][300010], a[13];

ll cifr(ll n)
{
    if (n == 0)
        return 1;
    ll s = 0, m = n;
    while (m > 0)
    {
        s++;
        m /= 10;
    }

    return s;
}

ll raz(ll n, ll m)
{
    if (cifr(n) != cifr(m))
        return INF;
    ll s = 0, n1 = n, m1 = m;

    while (n1 > 0)
    {
        if (n1 % 10 != m1 % 10)
            s++;
        n1 /= 10;
        m1 /= 10;
    }

    return s;
}

int main()
{
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    ll n, m, kol = 0, i, j, k;
    cin >> n >> m;

    if (n % m == 0)
    {
        cout << n << endl;
        return 0;
    }

    if (n < 10)
    {
        cout << 0 << endl;
        return 0;
    }

    if (m > DL)
    {
        ll t, kl, val = -1, mn = INF, p;
        t = 0;
        kl = cifr(n);

        while (cifr(t) <= kl)
        {
            p = raz(t, n);
            if (p < mn)
            {
                mn = p;
                val = t;
            }
            t += m;
        }

        cout << val << endl;
        return 0;
    }

    while (n > 0)
    {
        a[kol++] = n % 10;
        n /= 10;
    }

    reverse(a, a + kol);

    for (i = 0; i < m; i++)
    {
        dp[0][i] = INF;
        pr[0][i] = -1;
    }

    for (i = 1; i < 10; i++)
    {
        if (i == a[0])
        {
            dp[0][i % m] = 0;
            pr[0][i % m] = i;
        }

        else if (dp[0][i % m] > 1)
        {
            dp[0][i % m] = 1;
            pr[0][i % m] = i;
        }

    }

    for (i = 1; i < kol; i++)
    {
        for (j = 0; j < m; j++)
        {
            dp[i][j] = INF;
            pr[i][j] = -1;
        }

        for (j = 0; j < m; j++)
            if (dp[i - 1][j] != INF)
            {
                for (k = 0; k < 10; k++)
                {
                    if (k == a[i])
                    {
                        if (dp[i - 1][j] < dp[i][(j * 10 + k) % m])
                        {
                            dp[i][(j * 10 + k) % m] = dp[i - 1][j];
                            pr[i][(j * 10 + k) % m] = pr[i - 1][j] * 10 + k;
                        }
                    }

                    if (dp[i - 1][j] + 1 < dp[i][(j * 10 + k) % m])
                        {
                            dp[i][(j * 10 + k) % m] = dp[i - 1][j] + 1;
                            pr[i][(j * 10 + k) % m] = pr[i - 1][j] * 10 + k;
                        }
                }
            }
    }

    cout << pr[kol - 1][0] << endl;
    return 0;
}
