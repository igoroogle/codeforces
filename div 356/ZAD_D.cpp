#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll cube(ll n);
pair<ll, ll> cubeans(ll x);
int main()
{
    pair<ll, ll> mx = mp(0, 0);
    ll n;
    cin >> n;
    mx = cubeans(n);
    cout << mx.x << ' ' << mx.y << endl;
    return 0;
}

ll cube(ll n)
{
    ll x = 1;
    while (x * x * x <= n)
        x++;
    x--;
    return x;
}

pair<ll, ll> cubeans(ll x)
{
    //cout << x  << endl;
    if (x < 8)
        return mp(x, x);

    ll t = cube(x), f = t + 1, g = t - 1;
    if (x >= f * f * f - 1)
    {
        pair<ll,ll> k = cubeans(f * f * f - t * t * t - 1);
        k = mp(k.x + 1, k.y + t * t * t);
        return k;
    }

    pair<ll,ll> k = cubeans(x - t * t * t);
    k = mp(k.x + 1, k.y + t * t * t);
    pair<ll,ll> u = cubeans(t * t * t - g * g * g - 1);
    u = mp(u.x + 1, u.y + g * g * g);
    return max(u, k);
}
