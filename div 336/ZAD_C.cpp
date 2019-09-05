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
ll dp[100010],  stand[DL], sum[1000100];
pair <ll, ll> a[100010];
string s1, s2;
int main()
{
    ll n, x, y, kl, len = 0, ans = INF, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        a[i] = mp(x, y);
        sum[x]++;
    }
    sort(a, a + n);

    for (i = 0; i < DL; i++)
        stand[i] = -1;
    for (i = 1; i < DL; i++)
        sum[i] = sum[i - 1] + sum[i];
    for (i = 0; i < n - 1; i++)
    {
        j = a[i].x;
        while (a[i + 1].x > j)
            {
                stand[j] = i;
                j++;
            }
    }

    stand[a[n - 1].x] = n - 1;
    dp[0] = 0;

    for (i = 1; i < n; i++)
    {
        kl = 0;
        if (a[i].x - a[i].y  <= 0)
            kl = sum[a[i].x] - 1;
        else
            {
                kl = sum[a[i].x] - sum[a[i].x - a[i].y - 1] - 1;
                if (stand[a[i].x - a[i].y - 1] != -1)
                    kl += dp[stand[a[i].x - a[i].y - 1]];
            }
        dp[i] = kl;
    }
    ans = n;
    for (i = 0; i < n; i++)
        ans = min(ans, n - i - 1 + dp[i]);
    cout << ans << endl;
    return 0;
}
