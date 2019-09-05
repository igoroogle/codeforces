#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
const ll a[] = {31,29,31,30,31,30,31,31,30,31,30,31};
typedef long double ld;
string s;
int main()
{
    ll n, i, j, l, r, ans = 0;
    cin >> l >> r;
    for (ll i = 1; i <= 60; i++)
        for (ll j = 0; j < i; j++)
        {
            n = (ll(1) << ll(i + 1)) - ll(1);
            n = n & (~(ll(1) << j));
            if ((n >= l) && (n <= r))
                ans++;
        }
    cout << ans << endl;
    return 0;
}
