#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979311600;
const ll INF = 1000000000000000000;
const ll DL = 300010;
ll a[DL], sum[DL], dp[DL], n, k;
ll rec(ll poz, ll kol, ll len);
int main ()
{
    ll i;
    for (i = 0; i < DL; i++) dp[i] = INF;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    sum[0] = 0;
    for (i = 1; i < n; i++)
        sum[i] = abs(a[i] - a[i - 1]) + sum[i - 1];
    cout << rec(0, 1, 3) << endl;
    return 0;
}
ll rec(ll poz, ll kol, ll len)
{
    if (kol == 0)
        return 0;
    if (len * kol + poz > n)
        return INF;
    if (dp[poz] != INF)
        return abs(dp[poz]);
    ll val, val2, ans = INF;
    val = sum[poz + len - 1] - sum[poz];
    val2 = rec(poz + len, kol - 1, len);
    if ((val < INF) && (val2 < INF) && (val + val2 < ans))
        ans = val + val2;
    val = rec(poz + 1, kol, len);
    if ((val < INF) && (val < ans))
        ans = val;
    if (ans == INF)
        dp[poz] = -INF;
    else
        dp[poz] = ans;
    return dp[poz];
}
