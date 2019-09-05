#include "bits/stdc++.h"

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
string s, us;
int main()
{
    freopen("ragnarok.in", "r", stdin);
    freopen("ragnarok.out", "w", stdout);
    ll n, i, val1, val2;
    getline(cin, s);
    n = s.length();
    us = s;
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
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            val1 = hashes[n - 1];
        else
            val1 = (hashes[n - 1] + MOD - hashes[i - 1]) % MOD;
        val2 = (uhashes[n - i - 1] * pw[i]) % MOD;
        if (val1 == val2)
        {
            if (i == 0)
                cout << s << endl;
            else
                cout << s << us.substr(n - i, i) << endl;
            return 0;
        }
    }
    return 0;
}





