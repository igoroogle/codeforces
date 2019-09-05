#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 103;
const int MOD = 1000000007;
const int INF = 20000000010;
ll dp[66][66], a[66], m, k;
ll rec(ll v);
int main()
{
    ll i, j, l, r, mm, x;
    cin >> m >> k;
    dp[0][0] = 1;
    for (i = 1; i < 65; i++)
        for (j = 0; j < 65; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0)
                dp[i][j] += dp[i - 1][j - 1];
        }
    l = 1;
    r = 1000000000000000000;
    /*while (l < r)
    {
        mm = (l + r) / 2;
        x = rec(mm + mm) - rec(mm);
        if (x < m) l = mm + 1;
        else r = mm;
    }*/
    cout << rec(6) << endl;
    return 0;
}

ll rec(ll v)
{
    ll cnt = 0, j = v, sum = 0, k1 = k, i;
    while (j > 0)
    {
        cnt++;
        a[cnt - 1] = j % 2;
        j /= 2;
    }
    reverse(a, a + cnt);
    for (i = 0; i < cnt; i++)
        if ((a[i])  && (k1 >= 0))
        {
            sum += dp[cnt - i][k1];
            cout << cnt - i << ' ' << k1 << endl;
            k1--;
        }
    return sum;
}
