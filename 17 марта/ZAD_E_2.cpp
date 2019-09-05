#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll P = 237;
const ll DL  = 300010;
const ll VL = 300000;
ll pw[DL], hashes0[DL], hashes1[DL], vans[DL], k, n, m;
bool ans[DL];
string s1, s2;
bool hash_comp(ll l1, ll r1, ll l2, ll r2);
bool binp(ll l1, ll r1, ll l2, ll r2, ll kl);
int main()
{
    freopen("melman.in", "r", stdin);
    freopen("melman.out", "w", stdout);
    ll i, kol = 0;
    cin >> s1 >> s2 >> k;
    m = s1.length();
    n = s2.length();
    pw[0] = 1;
    for (i = 1; i < DL; i++)
        pw[i] = (pw[i - 1] * P) % MOD;
    hashes0[0] = 0;
    for (i = 1; i <= s1.length(); i++)
        hashes0[i] = (hashes0[i - 1] + ll(s1[i - 1] - 'a' + ll(1)) * pw[i - 1]) % MOD;
    for (i = 1; i <= s2.length(); i++)
        hashes1[i] = (hashes1[i - 1] + ll(s2[i - 1] - 'a' + ll(1)) * pw[i - 1]) % MOD;
    for (i = 1; i <= m - n + 1; i++)
        ans[i] = binp(i, i + n - 1, 1, n, ll(2));
    for (i = 0; i <= m; i++)
        if (ans[i])
        {
            vans[kol] = i;
            kol++;
        }
    cout << kol << endl;
    for (i = 0; i < kol - 1; i++)
        printf("%I64d ", vans[i]);
    if (kol > 0)
        printf("%I64d\n", vans[kol - 1]);
    return 0;
}

bool hash_comp(ll l1, ll r1, ll l2, ll r2)
{
    ll val1 = (hashes0[r1] + MOD - hashes0[l1 - 1]) % MOD;
    val1 = (val1 * pw[VL - l1 + 1]) % MOD;
    ll val2 = (hashes1[r2] + MOD - hashes1[l2 - 1]) % MOD;
    val2 = (val2 * pw[VL - l2 + 1]) % MOD;
    return (val1 == val2);
}

bool binp(ll l1, ll r1, ll l2, ll r2, ll kl)
{
    if ((l1 > r1) || (l2 > r2))
        return 1;
    if (kl == 0)
        return hash_comp(l1, r1, l2, r2);
    ll l = 0, r = r1 - l1 + 1, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (hash_comp(l1, l1 + m, l2, l2 + m))
            l = m + 1;
        else
            r = m;
    }
    if (l > r1 - l1)
        return 0;
    if (l1 + l + k > r1)
        return 0;
    if (s1[l1 + l + k - 1] == s2[l2 + l + k - 1])
        return 0;
    return (binp(l1 + l + 1, l1 + l + k - 1, l2 + l + 1, l2 + l + k - 1, 0) &&  binp(l1 + l + k + 1, r1, l2 + l + k + 1, r2, 0));
}
