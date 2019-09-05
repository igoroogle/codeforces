#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    //freopen("berries.in", "r", stdin);
    //freopen("berries.out", "w", stdout);
    ll a, b, c, x, y, ans;
    cin >> a >> b >> c;
    if (c == 1)
    {
        cout << x << endl;
        return 0;
    }
    ans = x;
    y = 1;
    x = c;
    while ((y <= b) && (a / x > 0))
    {
        ans += x - a / x;
        y++;
        x *= c;
    }
    /*if (y <= b)
    {
        ans += x * ll(b - y + 1);
    }*/
    cout << ans << endl;
    return 0;
}
