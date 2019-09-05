#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 500010;
const ll MOD = 1000000007;
ll a[DL], sum[DL], a1[DL], sum1[DL];
int main()
{
    ll n, i, j, m, l, r;
    cin >> n;
    m = n * n;
    a[m] = 1;
    for (i = 0; i <= m; i++)
        sum[i + m] = 1;

    for (i = 1; i < n; i++)
    {
        for (j = -m; j <= m; j++)
        {
            l = max(-m - 1, j - i - 1);
            r = max(-m, j - 1);
            if (r < j)
            {
                if (l + m >= 0)
                    a1[j + m] = (sum[r + m] + MOD - sum[l + m]) % MOD;
                else
                    a1[j + m] = (sum[r + m]) % MOD;
            }

            l = j;
            r = min(j + i, m);
            if (r > j)
            {
                if (l + m >= 0)
                    a1[j + m] = (a1[j + m] + sum[r + m] + MOD - sum[l + m]) % MOD;
                else
                    a1[j + m] = (a1[j + m] + sum[r + m]) % MOD;
            }

            if (j - 1 + m >= 0)
                sum1[j + m] = (sum1[j - 1 + m] + a1[j + m]) % MOD;
            else
                sum1[j + m] = a1[j + m] % MOD;
        }

        for (j = -m; j <= m; j++)
        {
            a[j + m] = a1[j + m];
            sum[j + m] = sum1[j + m];
        }

    }

    cout << a[m] << endl;
    /*for (i = -m; i <= m; i++)
        cout << sum[i + m] << endl;*/
    return 0;
}
