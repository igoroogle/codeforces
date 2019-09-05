#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 1000100;
const ll INF = 2E9;
ll dp[501][501], a[501];
ll rec(ll l, ll r);
int main()
{
    ll i, j, n;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dp[i][j] = -1;
    //cout << rec(1, 1) << endl;
    cout << rec(0, n - 1) << endl;
    return 0;
}

ll rec(ll l, ll r)
{
    if (dp[l][r] != -1)
        return dp[l][r];

    if (l == r)
    {
        dp[l][r] = 1;
        return 1;
    }
    ll ans = r - l + 1, i, val;

    if (l + 1 == r)
    {
        if (a[l] == a[r])
            ans = 1;
        else
            ans = 2;
        dp[l][r] = ans;
        return ans;
    }


    ans = min(rec(l + 1, r) + 1, rec(l, r - 1) + 1);
    for (i = l + 1; i <= r; i++)
    {
        //cout << l << ' ' << r << ' ' << i << endl;
        if (i < r)
            ans = min(rec(l, i) + rec(i + 1, r), ans);

        if (a[i] == a[l])
        {
            if (i == l + 1)
            {
                ans = min(ans, rec(i + 1, r) + 1);
            }
            else if (i == r)
                ans = min(ans, rec(l + 1, r - 1));
            else
                ans = min(ans, rec(l + 1, i - 1) + rec(i + 1, r));
        }
    }

    dp[l][r] = ans;
    return ans;
}
