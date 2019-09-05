#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2000000000000000000;
bool del(ll v);
int main()
{
    ll n, mx = 1, i, al, bl;
    cin >> n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            al = i;
            bl = n / i;
            if ((al > mx) && (del(al)))
                mx = al;
            if ((bl > mx) && (del(bl)))
                mx = bl;
        }
    if ((n > mx) && (del(n)))
        mx = n;
    cout << mx << endl;
    return 0;
}

bool del(ll v)
{
    ll i;
    for (i = 2; i * i <= v; i++)
        if (v % (i * i) == 0)
            return 0;
    return 1;
}
