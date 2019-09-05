#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
bool prost(ll p);
int main()
{
    ll n, a, b, c;
    cin >> n;
    if (prost(n))
    {
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }
    a = n / 3;
    b = n / 3;
    c = n / 3;
    while (a + b + c < n)
        c++;
    while (!prost(c))
    {
        c++;
        a--;
    }

    while (!prost(b) || !prost(a))
    {
        b++;
        a--;
    }
    cout << 3 << endl;
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}

bool prost(ll p)
{
    ll i;
    if (!(p % 2))
        return 0;
    for (i = 3; i * i <= p; i += 2)
        if (!(p % i))
            return 0;
    return 1;
}
