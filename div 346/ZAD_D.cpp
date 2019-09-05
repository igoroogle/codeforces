#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
ll x[1010], y[1010];
ll n;
bool prv(ll a1, ll b1, ll c1);
void getpr(ll x1, ll y1, ll x2, ll y2, ll &a, ll &b, ll &c);
bool mid (ll x, ll y, ll x1, ll y1, ll x2, ll y2);
int main()
{
    ll i, xn, yn, a, b, c, ans = 0;
    cin >> n;
    for (i = 0; i <= n; i++)
        scanf("%I64d%I64d", &x[i], &y[i]);

    for (i = 0; i < n; i++)
    {
        xn = -(y[i + 1] - y[i]) + x[i];
        yn = x[i + 1] - x[i] + y[i];
        getpr(x[i], y[i], x[i + 1], y[i + 1], a, b, c);

        if (prv(a, b, c))
        {
            ans++;
            continue;
        }

        getpr(x[i], y[i], xn, yn, a, b, c);

        if (prv(a, b, c))
        {
            ans++;
            continue;
        }
    }


    cout << ans << endl;
    return 0;
}

void getpr(ll x1, ll y1, ll x2, ll y2, ll &a, ll &b, ll &c)
{
    a = y1 - y2;
    b = x2 - x1;
    c = - (a * x1 + b * y1);
}

bool prv(ll a1, ll b1, ll c1)
{
    ll a2, b2, c2, xx, yy, z, i;
    for (i = 0; i < n; i++)
    {
        getpr(x[i], y[i], x[i + 1], y[i + 1], a2, b2, c2);
        z = a1 * b2 - a2 * b1;
        if (z == 0)
            continue;
        xx = (b1 * c2 - b2 * c1) / z;
        yy = (c1 * a2 - c2 * a1) / z;
        if (mid(xx, yy, x[i], y[i], x[i + 1], y[i + 1]))
            return 1;
    }
}

bool mid(ll x, ll y, ll x1, ll y1, ll x2, ll y2)
{
    //cout << x << ' ' << y
    if (x1 == x2)
    {
        if ((y > min(y1, y2)) && (y < max(y1, y2)))
            return 1;
        return 0;
    }

    if (y1 == y2)
    {
        if ((x > min(x1, x2)) && (x < max(x1, x2)))
            return 1;
        return 0;
    }

}
