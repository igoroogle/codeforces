#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll vis(ll y);
int main()
{
    ll y, vs, x = 0;
    cin >> y;
    vs = vis(y);
    if (vs)
        x = (x + 2) % 7;
    else
        x = (x + 1) % 7;
    y++;
    for(;;)
    {
        if ((x == 0) && (vis(y) == vs))
            break;
        if (vis(y))
            x = (x + 2) % 7;
        else
            x = (x + 1) % 7;
        y++;
    }

    cout << y << endl;
    return 0;
}

ll vis(ll y)
{
    if (y % 400 == 0)
        return 1;
    if ((y % 4 == 0) && (y % 100 != 0))
        return 1;
    return 0;
}
