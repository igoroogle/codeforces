#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[200010], sm[200010], lef[200010], rig[200010];
char a[200010];
int main()
{
    ll n, i, vl = 0, vl2 = 0;
    scanf("%s", &a);
    n = strlen(a);
    dp[0] = 0;
    sm[0] = 1;
    dp[1] = 0;
    sm[1] = 1;
    if (a[0] == '9')
        dp[1] = 1;
    vl = 0;
    lef[0] = 0;
    for (i = 1; i <= n; i++)
    {
        if (a[i - 1] == '0')
            lef[i] = lef[i - 1];
        else if (a[i - 1] == '9')
            lef[i] = 1;
        else if ((i - 2 >= 0) && (ll(a[i - 1] - '0') + ll(a[i - 2] - '0') == 9))
            lef[i] = 2;
        else
            lef[i] = 0;
    }
    rig[n + 1] = 0;
    for (i = n; i >= 1; i--)
    {
        if (a[i - 1] == '0')
            rig[i] = rig[i + 1];
        else if (a[i - 1] == '9')
            rig[i] = 1;
        else if ((i < n) && (ll(a[i - 1] - '0') + ll(a[i] - '0') == 9))
            rig[i] = 2;
        else
            rig[i] = 0;
    }
    vl = 1;
    vl2 = 0;
    for (i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        sm[i] = sm[i - 1];
        if (a[i - 1] == '9')
            dp[i]++;
        if ((a[i - 1] == '0') && ((rig[i] == 1) || (lef[i] == 1)))
        {
            dp[i] = dp[vl];
            sm[i] = sm[vl] * (i - vl + 1);
        }
        else if ((a[i - 1] == '0') && (lef[i] == 2))
        {
            dp[i] = dp[vl - 1];
            sm[i] = sm[vl - 1];
            if (dp[vl - 2] + 1 > dp[i])
            {
                dp[i] = (dp[vl - 2] + 1) * (i - vl + 1);
            }
            else if (dp[vl - 2] + 1 == dp[i])
            {
                dp[i] += (dp[vl - 2] + 1) * (i - vl + 1);
            }
        }
        if ((ll(a[i - 1] - '0') + ll(a[i - 2] - '0') == 9) && (a[i - 1] != '0') && (a[i - 2] != '0') && (i - 3 >= 0) && (a[i - 3] == '0') && (rig[i - 2] == 2))
        {
            dp[i] = dp[i - 1];
            sm[i] = sm[i - 1];
            if (dp[vl2] + 1 > dp[i])
            {
                dp[i] = dp[vl2] + 1;
                sm[i] = sm[vl2] * (i - vl2);
            }
            else if (dp[vl2] + 1 == dp[i])
            {
                sm[i] = sm[i - 1] + sm[vl2] * (i - vl2);
            }
        }
        else if ((ll(a[i - 1] - '0') + ll(a[i - 2] - '0') == 9) && (a[i - 1] != '0') && (a[i - 2] != '0'))
        {
            if (dp[i - 2] + 1 > dp[i])
            {
                dp[i] = dp[i - 2] + 1;
                sm[i] = sm[i - 2];
            }
            else if (dp[i - 2] + 1 == dp[i])
                sm[i] = sm[i - 1] + sm[i - 2];
        }

    if (a[i - 1] != '0')
        {
            vl2 = vl;
            vl = i;
        }
    }
    cout << sm[n] << endl;
    return 0;
}
