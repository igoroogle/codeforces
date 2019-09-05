#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
ll t[100010];
int main()
{
    freopen("minitrue.in", "r", stdin);
    freopen("minitrue.out", "w", stdout);
    ll i, j, n, x, tm, tx, a = 0, b = 0, c = 0, mx = INF;
    cin >> n;
    for (i = 1; i <= n; i++)
        {
            scanf("%I64d", &x);
            t[i] = t[i - 1] + x;
        }
    for (i = 1; i <= n - 2; i++)
        for (j = i + 1; j <= n - 1; j++)
        {
            tm = max(t[i], max(t[j] - t[i], t[n] - t[j]));
            tx = min(t[i], min(t[j] - t[i], t[n] - t[j]));
            if (tm - tx < mx)
            {
                mx = tm - tx;
                a = i;
                b = j - i;
                c = n - j;
            }
        }
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
