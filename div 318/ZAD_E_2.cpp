#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
ll a[100010], sum[100010];
int main()
{
    ll i, j, k, n, s = 0, smax = 0, vt = INF;
    cin >> n;
    for (i = 0; i < n; i++)
        {
            scanf("%I64d", &a[i]);
            smax += a[i] * ll(i + 1);
            s += a[i];
            sum[i] = s;
        }
    smax = max(smax, ll(0));
    while (sum[n - 1] != vt)
    {
        vt = sum[n - 1];
        j = 1;
        s = 0;
        for (i = 0; i < n; i++)
        {
            if (sum[n - 1] - sum[i] + j * a[i] >= 0)
            {
                sum[i] = sum[i - 1] + a[i];
                s += j * a[i];
                smax = max(smax, s);
                j++;
            }
            else
                sum[i] = sum[i - 1];
        }
    }
    cout << smax << endl;
    return 0;
}
