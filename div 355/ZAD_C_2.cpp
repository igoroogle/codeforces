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
ll val[64];
int main()
{
    ll n, i, j, k, x;
    ll ans = 0, vl = 0;
    scanf("%s", &s);
    n = strlen(s);
    x = getint(s[0]);
    for (i = 1; i < n; i++)
        x &= getint(s[i]);
    //cout << x << endl;
    for (i = 0; i <= 63; i++)
    {
        val[i] = 1;
        for (j = 0; j <= 63; j++)
            for (k = 0; k <= 63; k++)
                if ((j != k) && ((j & k) == i))
                    val[i] = (val[i] + ll(1)) % MOD;
    }

    ans = 1;
    for (i = 0; i < n; i++)
        ans = (ans * val[getint(s[i])]) % MOD;
    cout << ans << endl;
    //cout << val[61] << endl;
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
