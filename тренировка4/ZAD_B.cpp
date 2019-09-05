#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20010], dp[200010];
pair <ll, ll> b[200010];
map <ll, ll> ind;
int main()
{
    ll n, i, m = 0, t = 1, l = 0, indx;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &b[i].second, &b[i].first);
        m++;
        a[m] = b[i].second;
        m++;
        a[m] = b[i].first;
    }
    sort(a + 1, a + m + 1);
    sort(b, b + n);
    m++;
    for (i = 1; i < m; i++)
    if (a[i] != a[i - 1])
    {
        t++;
        a[t - 1] = a[i];
    }
    m = t;
    dp[0] = 0;
    ind[0] = 0;
    for (i = 1; i < m; i++)
    {
        dp[i] = dp[i - 1];
        ind[a[i]] = i;
        while ((l < m) && (b[l].first < a[i])) l++;
        while ((l < m) && (b[l].first == a[i]))
        {
            indx = ind[b[l].second];
            dp[i] = max(dp[indx] + 1, dp[i]);
            l++;
        }
    }
    cout << dp[m - 1] << endl;
    return 0;
}
