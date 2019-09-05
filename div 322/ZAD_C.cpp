#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair <ll, ll> a[100010];
int main()
{
    ll n, k, i, sm = 0;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i].second);
        a[i].first = a[i].second % 10;
    }
    sort(a, a + n);
    reverse(a, a + n);
    for (i = 0; i < n; i++)
    {
        sm += a[i].second / 10;
        if ((k >= 10 - a[i].first) && (a[i].second < 100))
        {
            a[i].second += (10 - a[i].first);
            k = k - 10 + a[i].first;
            sm++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (k < 10)
            break;
        if (a[i].second < 100)
        {
            if ((100 - a[i].second) <= k)
            {
                sm += (100 - a[i].second) / 10;
                k -= (100 - a[i].second);
            }

            else
            {
                sm += k / 10;
                break;
            }
        }
    }
    cout << sm << endl;
    return 0;
}
