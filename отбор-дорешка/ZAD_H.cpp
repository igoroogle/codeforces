#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1E9;
int dp[19][262144], a[19], b[19][19], bits[262144];
bool pr[19];

bool isbit(int n, int i)
{
    return bool((1 << i) & n);
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int n, k, i, j, p, t, val;

    cin >> n >> k;

    for (i = 0; i < k; i++)
        cin >> a[i];

    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            cin >> b[i][j];

    for (i = 0; i < (1 << n); i++)
    {
        j = i;
        p = 0;

        while (j > 0)
        {
            p += j % 2;
            j /= 2;
        }

        bits[i] = p;
    }

    p = 0;
    pr[0] = 1;
    for (i = 0; i < k; i++)
        {
            p += a[i];
            pr[p] = 1;
        }

    for (i = 0; i <= n; i++)
        for (j = 0; j < (1 << n); j++)
            dp[i][j] = INF;
    dp[0][0] = 0;

    for (i = 0; i < (1 << n); i++)
        for (j = 0; j <= n; j++)
            {
                if (j == n)
                    t = 0;
                else
                    t = j + 1;

                if (dp[t][i] < INF)
                {
                    if ((pr[bits[i]]) && (t != 0))
                    {
                        //cout << "null " << i << ' ' << t << endl;
                        val = dp[t][i] + b[t][0];
                        //cout << val << endl;
                        dp[0][i] = min(val, dp[0][i]);
                        continue;
                    }


                    for (p = 0; p < n; p++)
                        if (!isbit(i, p))
                        {
                            //cout << i << ' ' << t << ' ' << p + 1 << ' ' << (i | (1 << p)) << endl;
                            val = dp[t][i] + b[t][p + 1];
                            //cout << val << endl;
                            dp[p + 1][i | (1 << p)] = min(val, dp[p + 1][i | (1 << p)]);
                        }
                }
            }

    cout << dp[0][(1 << n) - 1] << endl;
    return 0;
}

/*
2 2
1 1
0 1 2
1 0 3
2 3 0
*/

/*
4 2
2 2
0 1 4 2 5
1 0 2 6 6
4 2 0 6 6
2 6 6 0 2
5 6 6 2 0
*/
