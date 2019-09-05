#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[110], poz[110], val[110], val2[110];
bool fir[27], las[27];
string a, c;
int main()
{
    int b, d, n, m, i, j, k, ps, mx = 0, sm = 0, vt;
    cin >> b >> d >> a >> c;
    n = a.length();
    m = c.length();
    for (i = 0; i < n; i++)
        fir[int(a[i] - 'a')] = 1;

    for (i = 0; i < m; i++)
        las[int(c[i] - 'a')] = 1;

    for (i = 0; i < 26; i++)
        if (fir[i] < las[i])
        {
            cout << 0 << endl;
            return 0;
        }

    for (i = 0; i < n; i++)
    {
        k = 0;
        ps = 0;
        j = i;
        for(;;)
        {
            if (j == 0)
                ps++;

            if (c[k] == a[j])
                k++;

            if (k == m)
            {
                dp[i] = ps;
                poz[i] = (j + 1) % n;
                break;
            }
            j = (j + 1) % n;
        }
    }
    for (i = 0; i < n; i++)
        val[i] = -1;
    i = 0;
    sm = 0;
    mx = 0;
    for(;;)
    {
        if (val[i] == -1)
            {
                val[i] = sm;
                val2[i] = mx;
            }

        else
        {
            vt = (b - val[i]) / (sm - val[i]);
            mx = val2[i] + vt * (mx - val2[i]);
            sm = val[i] + vt * (sm - val[i]);
            break;
        }

        if (sm + dp[i] <= b)
        {
            mx++;
            sm += dp[i];
            i = poz[i];
        }
        else break;
    }

    while (sm + dp[i] <= b)
    {
        mx++;
        sm += dp[i];
        i = poz[i];
    }

    cout << mx / d << endl;
    return 0;
}
