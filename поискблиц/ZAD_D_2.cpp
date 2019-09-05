#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <ll, bool> td;
int main()
{
    ll i, j, k, n, x, t, p, ans = 0;
    cin >> x;
    for (n = 1; n <= 11; n++)
    {
        for (i = 0; i < (ll(1) << n); i++)
        {
            for (k = 0; k <= 9; k++)
                for (p = 0; p <= 9; p++)
                    {
                        t = 0;
                        for (j = 0; j < n; j++)
                        {
                            if ((ll(1) << j) & i)
                                t = t * ll(10) + k;
                            else
                                t = t * ll(10) + p;
                        }
                        if ((t > 0) && (t <= x) && (!td[t]))
                        {
                            td[t] = 1;
                            ans++;
                        }
                    }
        }
    }
    cout << ans << endl;
    return 0;
}
