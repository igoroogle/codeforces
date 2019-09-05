#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2000000000;
string s;
int dp[5003][5003];
bool dp2[5003][5003];
void rec(int l, int r);
int main()
{
    int n, ind = 0, m, i, j, l, r;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            dp[i][j] = -INF;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            rec(i, j);
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        l--;
        r--;
        printf("%d\n", dp[l][r]);
    }
    return 0;
}
void rec(int l, int r)
{
    if (dp[l][r] != -INF)
        return;

    if (l == r)
    {
        dp[l][r] = 1;
        dp2[l][r] = 1;
        return;
    }

    if (l + 1 == r)
    {
        dp[l][r] = 2;
        dp2[l][r] = 0;
        if (s[l] == s[r])
            {
                dp[l][r]++;
                dp2[l][r] = 1;
            }
        return;
    }
    rec(l, r - 1);
    rec(l + 1, r);
    rec(l + 1, r - 1);
    dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1];
    dp2[l][r] = 0;
    if ((dp2[l + 1][r - 1]) && (s[l] == s[r]))
    {
        dp2[l][r] = 1;
        dp[l][r]++;
    }
}
