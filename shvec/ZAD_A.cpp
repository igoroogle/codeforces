#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100][524288];
int a[19], b[10];
int main()
{
    int m, cnt = 0, j, i, k;
    ll n, p, ans;
    cin >> n >> m;
    p = n;
    while (p > 0)
    {
        cnt++;
        a[cnt - 1] = p % 10;
        p /= 10;
    }
    dp[0][0] = 1;
        for (i = 0; i < (int(1) << int(cnt)); i++)
            for (k = 0; k < m; k++)
                for (j = 0; j < cnt; j++)
                    if (((a[j] != 0) || (i > 0)) && ((int(i) | (int(1) << int(j))) != int(i)))
                        dp[(k * 10 + a[j]) % m][(int(i) | (int(1) << int(j)))] += dp[k][i];
    ans = dp[0][(int(1) << int(cnt)) - 1];

    for (i = 0; i < cnt; i++)
    {
        b[a[i]]++;
        if (b[a[i]] != 0)
            ans /= b[a[i]];
    }

    cout << ans << endl;
    return 0;
}
