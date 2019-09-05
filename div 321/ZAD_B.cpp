#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ll, ll> a[100010];
int main()
{
    ll i, n, d, mx = 0, val, l, r;
    cin >> n >> d;
    for (i = 0; i < n; i++)
        scanf("%I64d%I64d", &a[i].first, &a[i].second);
    sort(a, a + n);
    a[n].first = 2000000010;
    a[n].second = 0;
    val = a[0].second;
    l = 0;
    r = 0;
    while (r < n)
    {
        while (abs(a[r].first - a[l].first) >= d)
            {
                val -= a[l].second;
                l++;
            }
        mx = max(mx, val);
        r++;
        val += a[r].second;
    }
    cout << mx << endl;
    return 0;
}
