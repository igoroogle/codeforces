#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
int ms[] = {31,28,31,30,31,30,31,31,30,31,30,31};
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
int main()
{
    ll n, a, b, p, q, lc;
    cin >> n >> a >> b >> p >> q;
    lc = n / lcm(a, b);
    cout << ll(n / a - lc) * p + ll(n / b - lc) * q + lc * max(p,q) << endl;
    return 0;
}

ll gcd(ll a, ll b)
{
    //cout << a << ' ' << b << endl;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
