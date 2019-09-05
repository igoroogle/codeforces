#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ll a, b, a1 = 0, b1 = 0;
    cin >> a >> b;
    while (a + b > 1)
    {
        if ((a > 0) && (b > 0))
        {
            a1++;
            a--;
            b--;
        }
        else if (a > 1)
        {
            b1++;
            a -= 2;
        }
        else if (b > 1)
        {
            b1++;
            b -= 2;
        }
    }
    cout << a1 << ' ' << b1 << endl;
    return 0;
}
