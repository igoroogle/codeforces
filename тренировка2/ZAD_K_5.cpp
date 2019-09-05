#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define sqr(a) ((a) * (a))
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef unsigned int unt;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef double geom;

const ll MOD = 457839487523;
const ll P = 768477;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const int N = 300001;
const int M = 12001;
ll hashes[300010], uhashes[300010], pw[300010];
string s, us, s1, us1;
int main()
{
    //freopen("ragnarok.in", "r", stdin);
    //freopen("ragnarok.out", "w", stdout);
    ll n, i, val1, val2, ind1 = 500010, u1, ind2 = 500010, u2;
    getline(cin, s);
    n = s.length();
    us = s;
    u1 = 400010;
    u2 = u1;
    reverse(us.begin(), us.end());
    pw[0] = 1;
    for (i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * P) % MOD;
    hashes[0] = ll(s[0] - 'a' + 1);
    uhashes[0] = ll(us[0] - 'a' + 1);
    for (i = 1; i < n; i++)
        hashes[i] = (hashes[i - 1] + pw[i] * ll(s[i] - 'a' + 1)) % MOD;
    for (i = 1; i < n; i++)
        uhashes[i] = (uhashes[i - 1] + pw[i] * ll(us[i] - 'a' + 1)) % MOD;
    for (i = 0; i < n - 1; i++)
    {
        if (i == 0)
            val1 = hashes[n - 1];
        else
            val1 = (hashes[n - 1] + MOD - hashes[i - 1]) % MOD;
        val2 = (uhashes[n - i - 1] * pw[i]) % MOD;
        if (val1 == val2)
        {
            /*if (i == 0)
                cout << s << endl;
            else
                cout << s << us.substr(n - i, i) << endl;*/
            if ((i == 0) && (hashes[n - 1] != uhashes[n - 1]))
                continue;
            if (i > 0)
            {
                val1 = (hashes[n - 1] + MOD - hashes[i - 1]) % MOD;
                val1 = (((((uhashes[n - 1] + MOD - uhashes[n - i - 2]) % MOD) * pw[n - i]) % MOD) * pw[i] + val1) % MOD;
                val2 = (hashes[i]  + (uhashes[n - i - 1] * pw[i] % MOD)) % MOD;
                val2 = (val2 * pw[i]) % MOD;
                if (val1 != val2)
                    continue;
            }
            ind1 = i;
            break;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        if (i == 0)
            val1 = uhashes[n - 1];
        else
            val1 = (uhashes[n - 1] + MOD - uhashes[i - 1]) % MOD;
        val2 = (hashes[n - i - 1] * pw[i]) % MOD;
        if (val1 == val2)
        {
            /*if (i == 0)
                cout << s << endl;
            else
                cout << s << us.substr(n - i, i) << endl;*/
            if ((i == 0) && (uhashes[n - 1] != hashes[n - 1]))
                continue;
            if (i > 0)
            {
                val1 = (uhashes[n - 1] + MOD - uhashes[i - 1]) % MOD;
                val1 = (((((hashes[n - 1] + MOD - hashes[n - i - 2]) % MOD) * pw[n - i]) % MOD) * pw[i] + val1) % MOD;
                val2 = (uhashes[i]  + (hashes[n - i - 1] * pw[i] % MOD)) % MOD;
                val2 = (val2 * pw[i]) % MOD;
                if (val1 != val2)
                    continue;
            }
            ind2 = i;
            break;
        }
    }
    if ((ind1 <= ind2) && (ind1 < n))
    {
        if (ind1 != 0)
            s = s + us.substr(n - ind1, i);
    }
    else if (ind2 < n)
    {
        if (ind2 == 0)
            s = us;
        else
            s = us + s.substr(n - ind2, i);
    }
    else s = s + us;
    cout << s << endl;
    return 0;
}





