#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> a[1010];
int dp[1010], n, k;
int rec(int x);
int main()
{
    int i, j, x, ans = 0;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        dp[i] = -1;
    for (i = 0; i < k; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &x);
            x--;
            a[x].pb(j);
        }

    for (i = 0; i < n; i++)
        ans = max(ans, rec(i));

    cout << ans << endl;
    return 0;
}

int rec(int x)
{
    if (dp[x] != -1)
        return dp[x];
    int i, j;
    bool f;
    dp[x] = 1;
    for (i = 0; i < n; i++)
        if (i != x)
        {
            f = 1;
            for (j = 0; j < k; j++)
                if (a[x][j] < a[i][j])
                {
                    f = 0;
                    break;
                }
            if (f)
                dp[x] = max(dp[x], 1 + rec(i));
        }

    return dp[x];
}
