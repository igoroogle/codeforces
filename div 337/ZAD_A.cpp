#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E9;
ll a[200010], dnul[200010];
int main()
{
    ll n, i, ans = 0, mn = INF, val = 0, vv, mt;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            scanf("%I64d", &a[i]);
            mn = min(a[i], mn);
        }

    for (i = 0; i < n; i++)
        a[i] -= mn;
    ans = mn * n;

    for (i = n - 1; i >= 0; i--)
    {
        if (dnul[i] != 0)
        {
            dnul[i] = dnul[i + 1] + 1;
        }
    }
    mt = 0
    for (i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                vv = dnul[i];
                if (vv = n - i)
                    vv += mt;
                val = max(val, vv);
                mt++;
            }
            else
                mt = 0;
        }
    cout << val + ans << endl;
    return 0;
}
