#include <bits/stdc++.h>
#define mp mak_pair
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll getint(char c);
char s[100003];
ll val[64][100003];
int main()
{
    ll n, i, j, k, x;
    ll ans = 0, vl = 0;
    scanf("%s", &s);
    n = strlen(s);
    x = getint(s[0]);
    for (i = 1; i < n; i++)
        x &= getint(s[i]);
    cout << x << endl;
    //cout << x << endl;
    for (i = 0; i <= 63; i++)
        val[i][0] = 1;
    for (i = 1; i < n; i++)
        for (j = 0; j <= 63; j++)
            for (k = 0; k <= 63; k++)
                val[j & k][i] = (val[j & k][i] + val[j][i - 1]) % MOD;

    ans = 0;
    for (i = 0; i <= 63; i++)
        for (j = 0; j <= 63; j++)
            if ((i != j) && ((i & j) == x))
            {
                //cout << i << ' ' << j << ' ' << (i & j) << endl;
                ans = (val[i][n - 1] * val[j][n - 1] + ans) % MOD;
            }

    ans = (ans + val[x][n - 1] * val[x][n - 1]) % MOD;
    cout << ans << endl;
    return 0;
}

ll getint(char c)
{
    if ((c >= '0') && (c <= '9'))
        return ll(c - '0');
    if ((c >= 'A') && (c <= 'Z'))
        return ll(c - 'A' + 10);
    if ((c >= 'a') && (c <= 'z'))
        return ll(c - 'a' + 36);
    if (c == '-')
        return ll(62);
    if (c == '_')
        return ll(63);
}
