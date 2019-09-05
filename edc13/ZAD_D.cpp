#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll binpow(ll x, ll n);
ll divs(ll a, ll b);
int main()
{
    ll a, b, x, n, ans = 0, dt, vt, an;
    cin >> a >> b >> n >> x;
    an = binpow(a, n);
    ans = (an * x) % MOD;
    if (a != 1)
    {
        dt = (an + MOD - ll(1)) % MOD;
        dt = (dt * b) % MOD;
        vt = (a + MOD - ll(1)) % MOD;
        dt = divs(dt, vt);
    }
    else
    {
        dt = n % MOD;
        dt = (n * b) % MOD;
    }

    ans = (ans + dt) % MOD;
    cout << ans << endl;
    return 0;
}

ll binpow(ll x, ll n)
{
    if (n == 0)
        return ll(1);
    if (n == 1)
        return x;
    ll bn = binpow(x, n >> ll(1));
    bn = (bn * bn) % MOD;
    if (n & ll(1))
        bn = (bn * x) % MOD;
    return bn;
}

ll divs(ll a, ll b)
{
    //cout << binpow(b, MOD - ll(0)) << endl;
    return ll((a * binpow(b, ll(MOD - ll(2)))) % MOD);
}
